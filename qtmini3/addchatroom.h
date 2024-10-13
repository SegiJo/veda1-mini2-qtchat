#ifndef ADDCHATROOM_H
#define ADDCHATROOM_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class AddChatRoom;
}

class AddChatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit AddChatRoom(QSqlDatabase db,QWidget *parent = nullptr);
    ~AddChatRoom();

private slots:
    void onAddButtonClicked();   // "생성" 버튼 클릭 시 호출될 슬롯
    void onCloseButtonClicked();

private:
    Ui::AddChatRoom *ui;
    QSqlDatabase db;
};

#endif // ADDCHATROOM_H
