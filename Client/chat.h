#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);  // 생성자
    ~Chat();  // 소멸자

private slots:
    void onSendMessage();  // 메시지 전송 슬롯
    void onReceiveMessage();  // 메시지 수신 슬롯
    void onConnected();  // 연결 성공 시 호출
    void onDisconnected();  // 연결 종료 시 호출

private:
    void setupConnection(const QString &serverAddress, quint16 serverPort);  // IP 주소와 포트를 인자로 받는 연결 함수

private:
    Ui::Chat *ui;
    QTcpSocket *socket;  // TCP 소켓
};

#endif // CHAT_H
