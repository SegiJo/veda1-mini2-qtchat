#include "server.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFile>

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    // 데이터베이스 연결
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/kimjeonegeun/Desktop/qtmini3/build/Qt_6_7_2_macos-Debug/qtchat.db");

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
        clients.insert(clientSocket, QString());  // 사용자 이름(닉네임)은 나중에 설정
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

        // 로그인 요청 처리
        if (message.startsWith("USER_LOGIN:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 3) {
                QString username = parts.at(1);
                QString password = parts.at(2);

                if (validateUserAccount(username, password)) {
                    qDebug() << "로그인 성공: " << username << " 클라이언트 소켓 주소: " << clientSocket;
                    clientSocket->write("LOGIN_SUCCESS\n");
                } else {
                    if (createUserAccount(username, password)) {
                        clients[clientSocket] = username;
                        clientSocket->write("ACCOUNT_CREATED\n");
                        qDebug() << "계정 생성 후 로그인 성공: " << username;
                    } else {
                        clientSocket->write("LOGIN_FAILURE\n");
                    }
                }
                clientSocket->flush();
            }
        }

        // 클라이언트가 채팅방 목록을 요청할 경우 처리
        else if (message == "GET_CHATROOMS") {
            sendChatRoomList(clientSocket);  // 채팅방 목록 전송
        }

        // 클라이언트 검색 요청
        else if (message.startsWith("SEARCH:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 3) {
                QString column = parts.at(1); // 검색할 컬럼
                QString searchTerm = parts.at(2); // 검색어

                // SQL 쿼리 실행
                QString queryStr = QString("SELECT room_name, start_place, end_place FROM chatrooms WHERE %1 LIKE '%%2%'").arg(column).arg(searchTerm);
                QSqlQuery query(db);
                if (query.exec(queryStr)) {
                    QString result;
                    while (query.next()) {
                        QString roomName = query.value(0).toString();
                        QString startPlace = query.value(1).toString();
                        QString endPlace = query.value(2).toString();
                        result += roomName + "," + startPlace + "," + endPlace + "\n";
                    }

                    // 검색 결과 클라이언트에 전송
                    clientSocket->write(result.toUtf8());
                    clientSocket->flush();
                }
                else {
                    qCritical() << "검색 쿼리 실행 오류:" << query.lastError().text();
                    clientSocket->write("ERROR:SEARCH_QUERY_FAILED\n");
                    clientSocket->flush();
                }
            }

        }

        // 클라이언트 채팅방 추가 요청
        else if (message.startsWith("ADDCHATROOM_TABLE:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 4) {
                QString roomName = parts.at(1); // 검색할 컬럼
                QString startPlace = parts.at(2); // 검색어
                QString endPlace = parts.at(3); // 검색할 컬럼

                QSqlQuery query(db);

                // SQL 쿼리 생성
                query.prepare("INSERT INTO chatrooms (room_name, start_place, end_place) "
                              "VALUES (:roomName, :startPlace, :endPlace)");

                // 바인딩
                query.bindValue(":roomName", roomName);
                query.bindValue(":startPlace", startPlace);
                query.bindValue(":endPlace", endPlace);

                // 쿼리 실행
                if (!query.exec()) {
                    qCritical() << "채팅방 추가 실패: " << query.lastError().text();
                    clientSocket->write("ERROR:ADDCHATROOM_FAILED\n");
                } else {
                    qDebug() << "채팅방 추가 성공: " << roomName;
                    clientSocket->write("SUCCESS:CHATROOM_ADDED\n");
                }

                clientSocket->flush();

            }
        }

        // 채팅방 참가 요청 처리
        else if (message.startsWith("JOIN_CHATROOM:")) {
            QString roomName = message.section(":", 1, 1).trimmed();
            if (joinChatRoom(clientSocket, roomName)) {
                clientSocket->write("JOIN_SUCCESS\n");
            } else {
                clientSocket->write("JOIN_FAIL\n");
            }
            clientSocket->flush();
        }

        // 닉네임 설정
        else if (message.startsWith("NICKNAME:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 2) {
                QString nickname = parts.at(1).trimmed();
                clients[clientSocket] = nickname;  // 클라이언트의 닉네임 설정
                qDebug() << "닉네임 설정됨: " << nickname;
            }
        }

        // 채팅 메시지 처리
        else if (message.startsWith("MSG:")) {
            QString userMessage = message.section(":", 1, 1).trimmed();
            QString roomName = clientsRoomMap.value(clientSocket);  // 클라이언트가 속한 채팅방 이름
            QString nickname = clients.value(clientSocket);         // 클라이언트의 닉네임
            if (!roomName.isEmpty()) {
                broadcastToRoom(roomName, nickname, userMessage);  // 채팅방 내 클라이언트에 닉네임과 메시지 전송
            }
        }

        //파일 메세지
        else if(message.startsWith("FILE:")) {
            QStringList parts = message.split(":");
            if (parts.size() == 3) {
                QString fileName = parts[1];
                int fileSize = parts[2].toInt();
                QByteArray fileData = clientSocket->read(fileSize); // 파일 데이터 수신

                QFile file("받은_" + fileName); // 받은 파일 저장 경로
                if (file.open(QIODevice::WriteOnly)) {
                    file.write(fileData);
                    file.close();
                    qDebug() << "파일 저장 성공: " << fileName;

                    // 파일 수신 성공 메시지 클라이언트에 전송
                    clientSocket->write("FILE_RECEIVED\n");
                }else {
                    qWarning() << "파일 저장 실패: " << file.errorString();
                    clientSocket->write("ERROR:FILE_SAVE_FAILED\n"); // 에러 메시지 전송
                }
            }
        }
    }
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

    clientsRoomMap[client] = roomName;  // 클라이언트를 해당 채팅방에 추가
    qDebug() << "클라이언트가 채팅방에 참가: " << roomName;
    return true;
}

void Server::broadcastToRoom(const QString &roomName, const QString &nickname, const QString &message)
{
    QMutexLocker locker(&mutex);
    QString fullMessage = nickname + ": " + message;  // 닉네임과 메시지를 합침
    QByteArray messageData = fullMessage.toUtf8() + "\n";

    for (QTcpSocket *client : clientsRoomMap.keys()) {
        if (clientsRoomMap[client] == roomName) {
            client->write(messageData);  // 해당 채팅방의 클라이언트들에게만 닉네임과 함께 메시지 전송
            client->flush();
        }
    }
}

void Server::onDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        QMutexLocker locker(&mutex);
        qDebug() << "클라이언트 연결 종료";
        clientsRoomMap.remove(clientSocket);  // 클라이언트가 있던 채팅방에서 제거
        clients.remove(clientSocket);         // 클라이언트 목록에서 제거
        clientSocket->deleteLater();
    }
}

void Server::sendChatRoomList(QTcpSocket *client)
{
    QSqlQuery query;
    query.prepare("SELECT room_name, start_place, end_place FROM chatrooms");

    if (!query.exec()) {
        qCritical() << "채팅방 목록 조회 실패: " << query.lastError().text();
        client->write("ERROR: Failed to retrieve chat rooms\n");
        return;
    }

    QString chatRooms;
    while (query.next()) {
        QString roomName = query.value(0).toString();
        QString startPlace = query.value(1).toString();
        QString endPlace = query.value(2).toString();
        chatRooms += roomName + "," + startPlace + "," + endPlace + "\n";
    }

    // 클라이언트에게 채팅방 목록 전송
    client->write(chatRooms.toUtf8());
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
