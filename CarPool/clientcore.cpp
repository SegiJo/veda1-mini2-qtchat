#include "clientcore.h"
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>
#include <QSqlError>
#include <QMessageBox>

ClientCore::ClientCore() {
    socket = new QTcpSocket(this); // 소켓 초기화
    connect(socket, &QTcpSocket::readyRead, this, &ClientCore::onReadyRead);

}
bool ClientCore::connectServer(const QHostAddress &address, const quint16 &port) {
    // IP 주소와 포트가 유효한지 확인
    if (!address.isNull() && port > 0) {
        // qDebug() 대신 QMessageBox 사용
        QMessageBox::information(nullptr, "연결 중", "서버에 연결 중... " + address.toString() + ":" + QString::number(port));
    } else {
        QMessageBox::critical(nullptr, "오류", "IP 주소 또는 포트 번호가 유효하지 않습니다!");
        return false;
    }

    serverAddress = address;
    serverPort = port;

    // 서버에 TCP 소켓으로 연결
    socket->connectToHost(serverAddress, serverPort);

    if (socket->waitForConnected(3000)) {
        // qDebug() 대신 QMessageBox 사용
        QMessageBox::information(nullptr, "연결 성공", "서버 연결 성공!");
        return true;
    } else {
        // qDebug() 대신 QMessageBox 사용
        QMessageBox::critical(nullptr, "연결 실패", "서버 연결 실패: " + socket->errorString());
        return false;
    }
}

// 회원가입 요청 처리
bool ClientCore::registerRequest(const QString &userName, const QString &password, const QString &role) {
    if (userName.length() < 1 || userName.length() > 20) {
        QMessageBox::warning(nullptr, "유저명 길이 오류", "유저명 길이 오류!");
        return false;
    }
    if (password.length() < 6 || password.length() > 20) {
        QMessageBox::warning(nullptr, "비밀번호 길이 오류", "비밀번호 길이 오류!");
        return false;
    }
    if (role != "root" && role != "admin" && role != "user") {
        QMessageBox::warning(nullptr, "역할 오류", "역할은 'root', 'admin', 'user' 중 하나여야 합니다.");
        return false;
    }

    // 데이터베이스에 새로운 사용자 정보 삽입
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, role) VALUES (?, ?, ?)");
    query.addBindValue(userName);
    query.addBindValue(password);
    query.addBindValue(role);

    if (query.exec()) {
        QMessageBox::information(nullptr, "계정 등록 성공", "계정 등록 성공!");
        return true;
    } else {
        QMessageBox::critical(nullptr, "계정 등록 실패", "계정 등록 실패: " + query.lastError().text());
        return false;
    }
}

// 로그인 요청 처리
bool ClientCore::loginRequest(const QString &userName, const QString &password) {
    // 데이터베이스에서 사용자 정보 확인
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(userName);
    query.addBindValue(password);

    if (query.exec() && query.next()) {
        currentUserName = userName;  // 현재 사용자 이름 저장
        QMessageBox::information(nullptr, "로그인 성공", "로그인 성공!");
        return true;
    } else {
        QMessageBox::critical(nullptr, "로그인 실패", "로그인 실패: 잘못된 사용자명 또는 비밀번호");
        return false;
    }
}

// 채팅방 생성 요청 처리
bool ClientCore::createChatroomRequest(const QString &chatName, const QString &start, const QString &finish, const QString &creatorName) {
    if (chatName.length() < 1 || chatName.length() > 20) {
        QMessageBox::warning(nullptr, "채팅방 이름 오류", "채팅방 이름이 잘못되었습니다!");
        return false;
    }

    // 데이터베이스에 새로운 채팅방 생성 (출발지와 도착지를 포함)
    QSqlQuery query;
    query.prepare("INSERT INTO chatrooms (chatname, start, finish, creatorname) VALUES (?, ?, ?, ?)");
    query.addBindValue(chatName);
    query.addBindValue(start);
    query.addBindValue(finish);
    query.addBindValue(creatorName);

    if (query.exec()) {
        QMessageBox::information(nullptr, "채팅방 생성 성공", "채팅방 생성 성공!");
        return true;
    } else {
        QMessageBox::critical(nullptr, "채팅방 생성 실패", "채팅방 생성 실패: " + query.lastError().text());
        return false;
    }
}

// 채팅방 참가 요청 처리
bool ClientCore::joinChatroomRequest(const QString &chatName, const QString &userName) {
    if (chatName.length() < 1 || chatName.length() > 20) {
        QMessageBox::warning(nullptr, "채팅방 이름 오류", "채팅방 이름이 잘못되었습니다!");
        return false;
    }

    // 데이터베이스에서 채팅방 존재 여부 확인 후 참가
    QSqlQuery query;
    query.prepare("INSERT INTO chatroom_members (chatname, username) VALUES (?, ?)");
    query.addBindValue(chatName);
    query.addBindValue(userName);

    if (query.exec()) {
        QMessageBox::information(nullptr, "채팅방 참가 성공", "채팅방 참가 성공!");
        return true;
    } else {
        QMessageBox::critical(nullptr, "채팅방 참가 실패", "채팅방 참가 실패: " + query.lastError().text());
        return false;
    }
}

// 채팅방 목록 요청 처리
bool ClientCore::getChatListRequest(const QString &userName) {
    QSqlQuery query;
    query.prepare("SELECT chatname FROM chatrooms");

    if (query.exec()) {
        joinedList.clear();
        while (query.next()) {
            joinedList.append(query.value(0).toString());
        }
        QMessageBox::information(nullptr, "채팅방 목록 가져오기 성공", "채팅방 목록 가져오기 성공!");
        return true;
    } else {
        QMessageBox::critical(nullptr, "채팅방 목록 가져오기 실패", "채팅방 목록 가져오기 실패: " + query.lastError().text());
        return false;
    }
}

// 메시지 전송 요청 처리
bool ClientCore::sendMessageRequest(const QString &chatName, const QString &senderName, const QString &message) {
    if (message.isEmpty()) {
        QMessageBox::warning(nullptr, "메시지 오류", "메시지가 비어있습니다!");
        return false;
    }

    // 서버로 메시지 전송
    QString dataToSend = chatName + ":" + senderName + ": " + message;
    socket->write(dataToSend.toUtf8());
    socket->flush();

    if (socket->waitForBytesWritten(3000)) {
        QMessageBox::information(nullptr, "메시지 전송 성공", "메시지 전송 성공!");
        return true;
    } else {
        QMessageBox::critical(nullptr, "메시지 전송 실패", "메시지 전송 실패!");
        return false;
    }
}

// 서버로부터 메시지 수신 처리
void ClientCore::onReadyRead() {
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "서버로부터 받은 메시지: " << message;

    emit readMessage(message);
}

bool ClientCore::sendAndWait(QString &response, const QString &message) {
    QTimer timer;
    QEventLoop loop;
    bool readFlag = false;  // 제한 시간 내에 데이터를 수신했는지 여부

    // 타이머와 이벤트 루프 연결 (제한 시간 초과 시 이벤트 루프 종료)
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

    // 서버로부터 메시지를 수신하면 루프를 종료하고 데이터를 처리
    connect(this, &ClientCore::readMessage, &loop, [&](const QString &receivedMessage){
        response = receivedMessage;
        readFlag = true;
        loop.quit();  // 이벤트 루프 종료
    });

    timer.start(10000);  // 10초 제한 시간 설정
    // sendMessage를 sendMessageRequest로 변경
    sendMessageRequest("chatName", currentUserName, message);  // 메시지 전송
    loop.exec();  // 이벤트 루프 대기

    return readFlag;  // 제한 시간 내에 응답을 수신했는지 여부 반환
}

QList<QString> ClientCore::getMessageRequest(const QString &chatName, const int latestMessageID, const QString &lastTime) {
    // 메시지 요청을 위한 데이터 생성
    QString requestData = QString("getMessage:%1:%2:%3").arg(chatName).arg(latestMessageID).arg(lastTime);

    // 서버에 메시지 요청 전송
    socket->write(requestData.toUtf8());
    socket->flush();

    // 응답 대기
    if (socket->waitForBytesWritten(3000)) {
        // 서버로부터 응답 수신
        QByteArray responseData = socket->readAll();
        QString response = QString::fromUtf8(responseData);
        qDebug() << "서버로부터 받은 응답: " << response;

        // 응답 처리 (여기서는 메시지 목록을 리스트로 변환)
        QList<QString> messageList;

        // 응답 형식에 따라 메시지를 파싱 (예시로 ':' 구분 사용)
        QStringList messages = response.split(":");
        for (const QString &message : messages) {
            if (!message.isEmpty()) {
                messageList.append(message);
            }
        }

        return messageList;
    } else {
        qDebug() << "메시지 요청 응답을 기다리는 중 오류 발생";
        return QList<QString>();
    }
}
