#ifndef CHATROOMWINDOW_H
#define CHATROOMWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QtNetwork>
#include "chatlistwindow.h"

namespace Ui {
class ChatRoomWindow;
}

class ChatRoomWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatRoomWindow(const QString &roomName, QTcpSocket *socket, QWidget *parent = nullptr);  // 생성자
    ~ChatRoomWindow();

private slots:
    //void refreshUserList();

    //void refreshChat();

    void onCloseButtonclicked();

    void onSendButtonclicked();

    void onSendFileButtonClicked(); // 파일 전송 버튼 클릭 시

    void onemoticonButtonClicked();

    //void onSendMessage();  // 메시지 전송 슬롯
    void onReceiveMessage();  // 메시지 수신 슬롯
    void onConnected();  // 연결 성공 시 호출
    void onDisconnected();  // 연결 종료 시 호출
    void onNameSetting();


private:
    void setupConnection(const QString &serverAddress, quint16 serverPort);  // IP 주소와 포트를 인자로 받는 연결 함수
private:
    Ui::ChatRoomWindow *ui;
    QTcpSocket *socket;
    QString roomName;

    QStringList userList;
    QStringList chatHistory;
    QList<int> chatMessageID;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    QPoint diff_pos;

    int latestMessageID;
    QString lastTime;
    QTimer *timer;

    QStringList emoticons;

};

#endif // CHATROOMWINDOW_H
