#ifndef CLIENTCORE_H
#define CLIENTCORE_H

#include <QtNetwork>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMap>
#include <QStringList>

class ChatRoomWindow;

class ClientCore : public QObject
{
    Q_OBJECT

public:
    static ClientCore& getInstance() {
        static ClientCore instance;
        return instance;
    }
     // 서버에 연결
    bool connectServer(const QHostAddress &address, const quint16 &port);

    bool registerRequest(const QString &userName, const QString &password, const QString &role);

    bool loginRequest(const QString &userName, const QString &password);
    // 채팅방 생성 요청
    bool createChatroomRequest(const QString &chatName, const QString &start, const QString &finish, const QString &creatorName);
    // 채팅방 참가 요청
    bool joinChatroomRequest(const QString &chatName, const QString &userName);
    // 채팅방 목록 요청
    bool getChatListRequest(const QString &userName);
    // 채팅 메시지 보내기
    bool sendMessageRequest(const QString &chatName, const QString &senderName, const QString &message);
    QList<QString> getMessageRequest(const QString &chatName, const int latestMessageID, const QString &lastTime);

    bool sendAndWait(QString &response, const QString &message);

signals:
    void readMessage(const QString &message);  // 메시지 수신 시 UI로 알림
private slots:
    void onReadyRead();  // 메시지 수신 시 처리
private:

    ClientCore();

public:
    // 멤버 변수
    QTcpSocket *socket;
    QHostAddress serverAddress;  // 서버 IP 주소
    quint16 serverPort;          // 서버 포트

    QString currentUserName;     // 현재 로그인한 사용자 이름

    QStringList joinedList;      // 참가한 채팅방 목록
    QStringList unjoinedList;    // 참가하지 않은 채팅방 목록
    QStringList selectList;      // 선택된 채팅방 목록
    QSqlDatabase db;

    QMap<QString, ChatRoomWindow*> nameChatMap; // 채팅방 이름과 ChatRoom 객체의 매핑
};

#endif // CLIENTCORE_H
