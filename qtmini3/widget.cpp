#include "widget.h"
#include "ui_widget.h"
#include "server.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 데이터베이스 초기화
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to initialize the database.");
        close();
        return;
    }

    // "생성" 버튼 클릭 시 서버 구동
    connect(ui->startButton, &QPushButton::clicked, this, &Widget::onStartButtonClicked);

    connect(ui->CloseButton, &QPushButton::clicked, this, &Widget::onCloseButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onStartButtonClicked()
{
    // 입력 필드에서 IP, 포트, 관리자 계정, 비밀번호 가져오기
    QString ipAddress = ui->ipLineEdit->text();
    quint16 port = ui->portLineEdit->text().toUShort();
    QString adminUsername = ui->adminLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (ipAddress.isEmpty() || port == 0 || adminUsername.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "모든 필드를 채워주세요.");
        return;
    }

    // 관리자 계정 검증
    if (!validateAdminAccount(adminUsername, password)) {
        // 등록되지 않은 경우 계정을 추가
        if (QMessageBox::question(this, "계정 등록", "입력한 계정이 존재하지 않습니다. 새 계정을 등록하시겠습니까?") == QMessageBox::Yes) {
            if (registerAdminAccount(adminUsername, password)) {
                QMessageBox::information(this, "계정 등록 완료", "계정이 성공적으로 등록되었습니다.");
            } else {
                QMessageBox::critical(this, "등록 실패", "계정 등록에 실패했습니다.");
                return;
            }
        } else {
            return;
        }
    }

    // 서버 인스턴스 생성 및 서버 시작
    Server *server = new Server(this);
    if (server->startServer(QHostAddress(ipAddress), port)) {
        QMessageBox::information(this, "서버 시작", "서버가 성공적으로 시작되었습니다.");
        this->close();

        // MainWindow에 데이터베이스 객체 전달
        MainWindow * mainwindow = new MainWindow(QSqlDatabase::database()); // 수정된 부분
        mainwindow->show();
    } else {
        QMessageBox::critical(this, "서버 시작 실패", "서버 시작에 실패했습니다.");
    }
}

bool Widget::initializeDatabase()
{
    // SQLite 데이터베이스 연결
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/kimjeonegeun/Desktop/qtmini3/build/Qt_6_7_2_macos-Debug/qtchat.db");  // 데이터베이스 파일 이름 지정

    if (!db.open()) {
        qDebug() << "데이터베이스 열기 실패:" << db.lastError().text();
        return false;
    }

    // admin 테이블 생성
    QSqlQuery query;
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS admin ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "username TEXT NOT NULL UNIQUE, "
                               "password TEXT NOT NULL)";
    if (!query.exec(createTableQuery)) {
        qDebug() << "테이블 생성 실패:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Widget::registerAdminAccount(const QString &username, const QString &password)
{
    // 비밀번호 해시화 (SHA-256)
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // SQLite에 계정 등록
    QSqlQuery query;
    query.prepare("INSERT INTO admin (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword);

    if (!query.exec()) {
        qDebug() << "관리자 계정 등록 실패:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Widget::validateAdminAccount(const QString &username, const QString &password)
{
    // SQLite에서 계정 검증
    QSqlQuery query;
    query.prepare("SELECT password FROM admin WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec() || !query.next()) {
        qDebug() << "계정 검증 실패 또는 계정 없음:" << query.lastError().text();
        return false;
    }

    // 데이터베이스에 저장된 비밀번호
    QString storedPassword = query.value(0).toString();

    // 입력된 비밀번호를 해시화하여 비교
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    return storedPassword == hashedPassword;
}

void Widget::onCloseButtonClicked()
{
    QApplication::quit();  // 프로그램 종료
}
