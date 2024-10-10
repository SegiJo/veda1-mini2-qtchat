#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QMutex>
#include <QSqlDatabase>
#include <QSqlQuery>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    bool startServer(const QHostAddress &address, quint16 port);  // 서버 시작

protected:
    void incomingConnection(qintptr socketDescriptor) override;  // 새로운 연결 수신

private slots:
    void onReadyRead();       // 클라이언트로부터 데이터 수신 시 호출
    void onDisconnected();    // 클라이언트 연결 종료 시 호출

private:
    void broadcastMessage(const QString &message);  // 메시지 브로드캐스트
    bool createUserAccount(const QString &username, const QString &password);  // 사용자 계정 생성
    bool validateUserAccount(const QString &username, const QString &password);  // 사용자 계정 검증
    void sendChatRoomList(QTcpSocket *client);      // 채팅방 목록 전송
    bool joinChatRoom(QTcpSocket *client, const QString &roomName);  // 채팅방 참가

    QSqlDatabase db;  // SQLite 데이터베이스 연결
    QMap<QTcpSocket*, QString> clients;  // 연결된 클라이언트와 사용자 이름 관리
    QMutex mutex;  // 클라이언트 접근을 위한 동기화 처리
};

#endif // SERVER_H
