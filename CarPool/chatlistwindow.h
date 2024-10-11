#ifndef CHATLISTWINDOW_H
#define CHATLISTWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStringList>
#include <QRegularExpression>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include <QtNetwork>
#include "loginwindow.h"

namespace Ui {
class ChatListWindow;
}

class ChatListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatListWindow(QWidget *parent = nullptr);
    ~ChatListWindow();
private slots:
    void receiveChatRoomList();

    void onJoinButtonclicked();

    void onNewChatButtonclicked();

    void onFindChatButtonclicked();

    void receiveSearchResults();

    void onBackButtonclicked();

private:
    Ui::ChatListWindow *ui;
    QString findName;
    QTcpSocket *socket;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    QPoint diff_pos;
};

#endif // CHATLISTWINDOW_H
