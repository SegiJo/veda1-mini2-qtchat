#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addchatroom.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QSqlDatabase database, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    db(database),
    chatroommodel(new QSqlQueryModel(this)),
    usermodel(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // 채팅방 테이블 설정
    setupChatRoomTable();

    // 테이블 뷰에서 모델 설정
    ui->chatTable->setModel(chatroommodel);

    // 테이블 뷰에서 채팅방 선택 시 슬롯 연결
    connect(ui->chatTable->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        QModelIndexList selected = ui->chatTable->selectionModel()->selectedRows();
        if (!selected.isEmpty()) {
            selectedChatRoom = selected.first().data().toString();
            qDebug() << "선택된 채팅방:" << selectedChatRoom;
        }
    });

    ui->userTable->setModel(usermodel);

    // 테이블 뷰에서 사용자 선택 시 슬롯 연결
    connect(ui->userTable->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        QModelIndexList selected = ui->userTable->selectionModel()->selectedRows();
        if (!selected.isEmpty()) {
            selectedUser = selected.first().data().toString();
            qDebug() << "선택된 사용자:" << selectedUser;
        }
    });

    // 슬롯 연결
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onCreateChatRoomClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteChatRoomClicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);

    //connect(ui->useraddButton, &QPushButton::clicked, this, &MainWindow::onCreateUserClicked);
    connect(ui->userdeleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteUserClicked);
    connect(ui->usersearchButton, &QPushButton::clicked, this, &MainWindow::onSearchUserButtonClicked);

    connect(ui->chatmanageButton, &QPushButton::clicked, this, &MainWindow::onMangeChatRoomClicked);

    // 초기화 시 모든 채팅방 불러오기
    loadAllChatRooms();
    loadAllusers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupChatRoomTable()
{
    // SQLite에 채팅방 테이블이 없으면 생성
    QSqlQuery query(db);
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS chatrooms ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "room_name TEXT NOT NULL UNIQUE, "
                               "start_place TEXT, "
                               "end_place TEXT)";
    if (!query.exec(createTableQuery)) {
        qCritical() << "테이블 생성 실패:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to create chatrooms table.");
    }
}

void MainWindow::loadAllChatRooms()
{
    // 모든 채팅방을 불러와서 테이블 뷰에 표시
    QString queryStr = "SELECT room_name, start_place, end_place FROM chatrooms";
    chatroommodel->setQuery(queryStr, db);

    if (chatroommodel->lastError().isValid()) {
        qCritical() << "채팅방 불러오기 오류:" << chatroommodel->lastError().text();
        QMessageBox::warning(this, "Error", "채팅방 목록을 불러오는 중 오류가 발생했습니다.");
    }

    // 테이블 뷰 열 크기 조정
    ui->chatTable->resizeColumnsToContents();
}

void MainWindow::onCreateChatRoomClicked()
{
    AddChatRoom * addchatroom = new AddChatRoom(QSqlDatabase::database()); // 수정된 부분
    addchatroom->show();

    // 모든 채팅방 다시 로드
    //loadAllChatRooms();
}

void MainWindow::onDeleteChatRoomClicked()
{
    if (selectedChatRoom.isEmpty()) {
        QMessageBox::warning(this, "삭제 오류", "삭제할 채팅방을 선택해주세요.");
        return;
    }

    // 선택된 채팅방을 데이터베이스에서 삭제
    QSqlQuery query(db);
    query.prepare("DELETE FROM chatrooms WHERE room_name = :room_name");
    query.bindValue(":room_name", selectedChatRoom);

    if (!query.exec()) {
        qCritical() << "채팅방 삭제 실패:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to delete chatroom.");
        return;
    }

    QMessageBox::information(this, "성공", "채팅방이 삭제되었습니다.");

    // 모든 채팅방 다시 로드
    loadAllChatRooms();
}

void MainWindow::onSearchButtonClicked()
{
    QString searchTerm = ui->chatlineEdit->text().trimmed();

    if (searchTerm.isEmpty()) {
        // 검색어가 없으면 모든 채팅방 표시
        loadAllChatRooms();
        return;
    }

    // 검색어로 필터링된 채팅방을 테이블 뷰에 표시
    QString queryStr = "SELECT room_name, start_place, end_place FROM chatrooms WHERE room_name LIKE '%" + searchTerm + "%'";
    chatroommodel->setQuery(queryStr, db);

    if (chatroommodel->lastError().isValid()) {
        qCritical() << "검색 오류:" << chatroommodel->lastError().text();
        QMessageBox::warning(this, "Error", "검색 중 오류가 발생했습니다.");
    } else {
        ui->chatTable->resizeColumnsToContents();  // 테이블 뷰 열 크기 조정
    }
}

void MainWindow::setupUserTable()
{
    // SQLite에 채팅방 테이블이 없으면 생성
    QSqlQuery query(db);
    QString createTableQuery = "INSERT INTO user (username, password) VALUES (:username, :password)";
    if (!query.exec(createTableQuery)) {
        qCritical() << "테이블 생성 실패:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to create user table.");
    }
}

void MainWindow::loadAllusers()
{
    // 모든 채팅방을 불러와서 테이블 뷰에 표시
    QString queryStr = "SELECT username FROM user";
    usermodel->setQuery(queryStr, db);

    if (usermodel->lastError().isValid()) {
        qCritical() << "사용자 불러오기 오류:" << usermodel->lastError().text();
        QMessageBox::warning(this, "Error", "채팅방 목록을 불러오는 중 오류가 발생했습니다.");
    }

    // 테이블 뷰 열 크기 조정
    ui->chatTable->resizeColumnsToContents();
}

/*
void MainWindow::onCreateUserClicked()
{
    QString userName = ui->userlineEdit->text().trimmed();
    if (userName.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "사용자 이름을 입력해주세요.");
        return;
    }

    // 채팅방을 데이터베이스에 추가
    QSqlQuery query(db);
    query.prepare("INSERT INTO user (username) VALUES (:username)");
    query.bindValue(":username", userName);

    if (!query.exec()) {
        qCritical() << "사용자 생성 실패:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to create user.");
        return;
    }

    QMessageBox::information(this, "성공", "사용자가 생성되었습니다.");

    // 모든 채팅방 다시 로드
    loadAllusers();
}
*/

void MainWindow::onDeleteUserClicked()
{
    if (selectedUser.isEmpty()) {
        QMessageBox::warning(this, "삭제 오류", "삭제할 사용자를 선택해주세요.");
        return;
    }

    // 선택된 채팅방을 데이터베이스에서 삭제
    QSqlQuery query(db);
    query.prepare("DELETE FROM user WHERE username = :username");
    query.bindValue(":username", selectedUser);

    if (!query.exec()) {
        qCritical() << "사용자 삭제 실패:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to delete user.");
        return;
    }

    QMessageBox::information(this, "성공", "사용자가 삭제되었습니다.");

    // 모든 채팅방 다시 로드
    loadAllusers();
}

void MainWindow::onSearchUserButtonClicked()
{
    QString searchTerm = ui->userlineEdit->text().trimmed();

    if (searchTerm.isEmpty()) {
        // 검색어가 없으면 모든 채팅방 표시
        loadAllusers();
        return;
    }

    // 검색어로 필터링된 채팅방을 테이블 뷰에 표시
    QString queryStr = "SELECT username FROM user WHERE username LIKE '%" + searchTerm + "%'";
    usermodel->setQuery(queryStr, db);

    if (usermodel->lastError().isValid()) {
        qCritical() << "검색 오류:" << usermodel->lastError().text();
        QMessageBox::warning(this, "Error", "검색 중 오류가 발생했습니다.");
    } else {
        ui->chatTable->resizeColumnsToContents();  // 테이블 뷰 열 크기 조정
    }
}

void MainWindow::onMangeChatRoomClicked()
{
    QMessageBox::warning(this, "Error", "준비중입니다.");
}

