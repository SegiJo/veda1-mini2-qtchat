#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QItemSelectionModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(QSqlDatabase db,QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onCreateChatRoomClicked();  // 채팅방 생성 버튼 클릭 슬롯
    void onSearchButtonClicked();    // 검색 버튼 클릭 슬롯
    void onJoinButtonClicked();
    void loadAllChatRooms();         // 모든 채팅방 불러오기

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *chatroommodel;  // 테이블 뷰에 데이터를 표시할 모델
    QString selectedChatRoom;  // 선택된 채팅방 이름
};

#endif // MAINWINDOW_H
