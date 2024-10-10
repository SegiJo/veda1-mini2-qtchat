#include "server.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    // 데이터베이스 연결
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("qtchat.db");

    if (!db.open()) {
        qCritical() << "데이터베이스 열기 실패: " << db.lastError().text();
    } else {
        QSqlQuery query;
        // 유저 테이블 생성
        QString createTable = "CREATE TABLE IF NOT EXISTS user ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "username TEXT NOT NULL UNIQUE, "
                              "password TEXT NOT NULL)";
        if (!query.exec(createTable)) {
            qCritical() << "유저 테이블 생성 실패: " << query.lastError().text();
        }

        // 채팅방 테이블 생성
        QString createChatTable = "CREATE TABLE IF NOT EXISTS chatrooms ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  "room_name TEXT NOT NULL UNIQUE)";
        if (!query.exec(createChatTable)) {
            qCritical() << "채팅방 테이블 생성 실패: " << query.lastError().text();
        }
    }
}

Server::~Server()
{
    QMutexLocker locker(&mutex);
    for (auto socket : clients.keys()) {
        socket->disconnectFromHost();
        socket->close();
        socket->deleteLater();
    }
    db.close();  // 서버 종료 시 데이터베이스 닫기
}

bool Server::startServer(const QHostAddress &address, quint16 port)
{
    if (!this->listen(address, port)) {
        qCritical() << "서버 시작 실패: " << this->errorString();
        return false;
    }
    qDebug() << "서버가 " << address.toString() << ":" << port << "에서 성공적으로 시작되었습니다.";
    return true;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *clientSocket = new QTcpSocket(this);

    // 전달받은 소켓 디스크립터를 설정
    if (clientSocket->setSocketDescriptor(socketDescriptor)) {
        QMutexLocker locker(&mutex);
        clients.insert(clientSocket, QString());  // 사용자 이름은 로그인 시 설정
        qDebug() << "새 클라이언트 연결됨, 소켓 주소: " << clientSocket;

        connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
        connect(clientSocket, &QTcpSocket::disconnected, this, &Server::onDisconnected);
    } else {
        // 소켓 디스크립터 설정 실패 시 처리
        delete clientSocket;
        qWarning() << "소켓 디스크립터 설정 실패";
    }
}

void Server::onReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        QByteArray data = clientSocket->readAll();
        QString message = QString::fromUtf8(data).trimmed();

        qDebug() << "수신된 데이터: " << message;
        qDebug() << "현재 클라이언트 소켓 주소: " << clientSocket;

        // 로그인 요청 처리
        if (message.startsWith("USER_LOGIN:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 3) {
                QString username = parts.at(1);
                QString password = parts.at(2);

                if (validateUserAccount(username, password)) {
                    clients[clientSocket] = username;  // 클라이언트의 사용자 이름 설정
                    qDebug() << "로그인 성공: " << username << " 클라이언트 소켓 주소: " << clientSocket;
                    clientSocket->write("LOGIN_SUCCESS\n");
                } else {
                    if (createUserAccount(username, password)) {
                        clients[clientSocket] = username;
                        clientSocket->write("ACCOUNT_CREATED\n");
                        qDebug() << "계정 생성 후 로그인 성공: " << username << ", 클라이언트 소켓 주소: " << clientSocket;
                    } else {
                        clientSocket->write("LOGIN_FAILURE\n");
                    }
                }
                clientSocket->flush();
            }
        }

        // 채팅 메시지 처리
        else if (message.startsWith("MSG:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 2) {
                QString userMessage = parts.at(1);
                QString username = clients.value(clientSocket);  // 현재 클라이언트의 사용자 이름 가져오기

                if (username.isEmpty()) {
                    qDebug() << "사용자 이름이 비어 있습니다. 클라이언트 소켓 주소: " << clientSocket;
                } else {
                    QString fullMessage = username + ": " + userMessage;
                    qDebug() << "브로드캐스트 메시지: " << fullMessage;
                    broadcastMessage(fullMessage);  // 모든 클라이언트에 메시지 브로드캐스트
                }
            }
        }
    }
}



void Server::onDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        QMutexLocker locker(&mutex);
        qDebug() << "클라이언트 연결 종료";
        clients.remove(clientSocket);  // 클라이언트 목록에서 제거
        clientSocket->deleteLater();
    }
}

void Server::broadcastMessage(const QString &message)
{
    QMutexLocker locker(&mutex);
    QByteArray messageData = message.toUtf8() + "\n";

    // 모든 클라이언트에게 메시지 전송 (자기 자신 포함)
    for (QTcpSocket *client : clients.keys()) {
        client->write(messageData);
        client->flush();
    }
}



bool Server::createUserAccount(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO user (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);  // 실제 환경에서는 비밀번호 해싱 필요

    if (!query.exec()) {
        qCritical() << "계정 생성 실패: " << query.lastError().text();
        return false;
    }

    qDebug() << "새 계정 생성됨: " << username;
    return true;
}

bool Server::validateUserAccount(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM user WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString storedPassword = query.value(0).toString();
        return (storedPassword == password);  // 실제 환경에서는 해싱된 비밀번호 비교 필요
    }

    return false;
}

void Server::sendChatRoomList(QTcpSocket *client)
{
    QSqlQuery query;
    query.prepare("SELECT room_name FROM chatrooms");

    if (!query.exec()) {
        qCritical() << "채팅방 목록 조회 실패: " << query.lastError().text();
        client->write("ERROR: Failed to retrieve chat rooms\n");
        return;
    }

    QString chatRooms;
    while (query.next()) {
        chatRooms += query.value(0).toString() + ",";
    }

    if (!chatRooms.isEmpty()) {
        chatRooms.chop(1);  // 마지막 컴마 제거
    }

    client->write(chatRooms.toUtf8() + "\n");
}

bool Server::joinChatRoom(QTcpSocket *client, const QString &roomName)
{
    QSqlQuery query;
    query.prepare("SELECT room_name FROM chatrooms WHERE room_name = :room_name");
    query.bindValue(":room_name", roomName);

    if (!query.exec() || !query.next()) {
        client->write("JOIN_FAIL\n");
        return false;
    }

    client->write("JOIN_SUCCESS\n");
    return true;
}
