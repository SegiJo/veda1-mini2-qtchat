#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QMap>
#include <QMutex>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);
    ~Server();

    bool startServer(const QHostAddress &address, quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    bool createUserAccount(const QString &username, const QString &password);
    bool validateUserAccount(const QString &username, const QString &password);
    void sendChatRoomList(QTcpSocket *client);
    bool joinChatRoom(QTcpSocket *client, const QString &roomName);
    void broadcastToRoom(const QString &roomName, const QString &nickname, const QString &message);

    QSqlDatabase db;
    QMutex mutex;
    QMap<QTcpSocket*, QString> clients;          // 클라이언트 소켓과 사용자 이름(닉네임)을 매핑
    QMap<QTcpSocket*, QString> clientsRoomMap;   // 클라이언트 소켓과 채팅방 이름을 매핑
};

#endif // SERVER_H
