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
    explicit ChatRoomWindow(const QString &chatName, QWidget *parent = nullptr); // 생성자 수정
    ~ChatRoomWindow();

private slots:
    void refreshUserList();

    void refreshChat();

    void onCloseButtonclicked();

    void onSendButtonclicked();

    void readyRead();
private:
    Ui::ChatRoomWindow *ui;
    QTcpSocket *socket;
    QString chatRoomName; // 채팅방 이름을 저장하는 변수
    QString currentChatName;
    QStringList userList;
    QStringList chatHistory;
    QList<int> chatMessageID;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    QPoint diff_pos;

    int latestMessageID;
    QString lastTime;
    QTimer *timer;

};

#endif // CHATROOMWINDOW_H
