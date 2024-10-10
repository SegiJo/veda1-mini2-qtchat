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
    explicit MainWindow(QSqlDatabase db, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCreateChatRoomClicked();  // 채팅방 생성 버튼 클릭 슬롯
    void onDeleteChatRoomClicked();  // 채팅방 삭제 버튼 클릭 슬롯
    void onSearchButtonClicked();    // 검색 버튼 클릭 슬롯
    void loadAllChatRooms();         // 모든 채팅방 불러오기

    //void onCreateUserClicked();  // 채팅방 생성 버튼 클릭 슬롯
    void onDeleteUserClicked();  // 채팅방 삭제 버튼 클릭 슬롯
    void onSearchUserButtonClicked();    // 검색 버튼 클릭 슬롯
    void loadAllusers();         // 모든 채팅방 불러오기

    void onMangeChatRoomClicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *chatroommodel;  // 테이블 뷰에 데이터를 표시할 모델
    QSqlQueryModel *usermodel;
    QString selectedChatRoom;  // 선택된 채팅방 이름

    QString selectedUser;

    void setupChatRoomTable();  // 채팅방 테이블 설정 함수
    void setupUserTable();  // 유저 테이블 설정 함수
};

#endif // MAINWINDOW_H
