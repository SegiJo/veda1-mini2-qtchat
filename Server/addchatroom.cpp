#include "addchatroom.h"
#include "ui_addchatroom.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

#include "mainwindow.h"

AddChatRoom::AddChatRoom(QSqlDatabase database, QWidget *parent)
    : QWidget(parent)
    ,db(database)
    ,ui(new Ui::AddChatRoom)
{
    ui->setupUi(this);

    connect(ui->addchatButton, &QPushButton::clicked, this, &AddChatRoom::onAddButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &AddChatRoom::onCloseButtonClicked);
}

AddChatRoom::~AddChatRoom()
{
    delete ui;
}

void AddChatRoom::onAddButtonClicked()
{
    QString roomName = ui->chatnameLineEdit->text().trimmed();
    QString startName = ui->startLineEdit->text().trimmed();
    QString endName = ui->endLineEdit->text().trimmed();
    if (roomName.isEmpty() || startName.isEmpty() || endName.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "빈 필드에 모두 입력해주세요.");
        return;
    }

    // 채팅방을 데이터베이스에 추가
    QSqlQuery query(db);
    query.prepare("INSERT INTO chatrooms (room_name,start_place,end_place) VALUES (:room_name,:start_place,:end_place)");
    query.bindValue(":room_name", roomName);
    query.bindValue(":start_place", startName);
    query.bindValue(":end_place", endName);

    if (!query.exec()) {
        qCritical() << "채팅방 생성 실패:" << query.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to create user.");
        return;
    }

    QMessageBox::information(this, "성공", "채팅방이 생성되었습니다.");

    this->close();
}

void AddChatRoom::onCloseButtonClicked()
{
    //MainWindow * mainwindow = new MainWindow(QSqlDatabase::database()); // 수정된 부분

    this->close(); // 현재 위젯 닫기
}
