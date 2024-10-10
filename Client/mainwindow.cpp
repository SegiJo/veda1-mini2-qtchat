#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chat.h"  // Chat 창 추가

#include "serverinfo.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 버튼과 슬롯 연결
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onCreateChatRoomClicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    connect(ui->joinButton, &QPushButton::clicked, this, &MainWindow::onJoinButtonClicked);
}

MainWindow::MainWindow(QSqlDatabase database, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    db(database),
    chatroommodel(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // 버튼과 슬롯 연결
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onCreateChatRoomClicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    connect(ui->joinButton, &QPushButton::clicked, this, &MainWindow::onJoinButtonClicked);

    // 시작 시 채팅방 목록 불러오기
    loadAllChatRooms();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCreateChatRoomClicked()
{
    qDebug() << "새 채팅방 추가 버튼이 클릭되었습니다.";
    // 채팅방 추가 로직을 여기에서 구현
}

void MainWindow::onSearchButtonClicked()
{
    qDebug() << "검색 버튼이 클릭되었습니다.";
    // 검색 로직을 여기에서 구현
}

void MainWindow::onJoinButtonClicked()
{
    // 채팅방 참가 로직
    qDebug() << "참가 버튼이 클릭되었습니다.";

    // Chat 창을 부모가 없는 독립된 창으로 생성
    Chat *chatWindow = new Chat(nullptr);  // 부모를 nullptr로 설정
    chatWindow->show();
}

void MainWindow::loadAllChatRooms()
{
    qDebug() << "채팅방 목록을 불러옵니다.";
    // 데이터베이스에서 채팅방 목록을 불러오는 로직을 여기에 구현
}
