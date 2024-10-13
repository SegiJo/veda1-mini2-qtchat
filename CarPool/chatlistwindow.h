#ifndef CHATLISTWINDOW_H
#define CHATLISTWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QStringList>
#include <QRegularExpression>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include <QtNetwork>
#include <QSqlDatabase>
#include <QTcpSocket>

#include "loginwindow.h"

namespace Ui {
class ChatListWindow;
}

class ChatListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatListWindow(QWidget *parent = nullptr);
    explicit ChatListWindow(QSqlDatabase db,QWidget *parent = nullptr);
     ~ChatListWindow();

private slots:

    void onJoinButtonclicked();

    void onNewChatButtonclicked(); // 채팅방 생성 버튼 클릭 슬롯

    void onFindChatButtonclicked();  // 검색 버튼 클릭 슬롯

    void loadAllChatRooms();

    void onBackButtonclicked();

private:
    Ui::ChatListWindow *ui;
    QString findName;
    QTcpSocket *socket;
    QSqlDatabase db;
    QSqlQueryModel *chatroommodel;  // 테이블 뷰에 데이터를 표시할 모델
    QString selectedChatRoom;  // 선택된 채팅방 이름

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    QPoint diff_pos;
};

#endif // CHATLISTWINDOW_H
