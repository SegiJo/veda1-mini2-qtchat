#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"  // 메인윈도우 포함

#include "serverinfo.h"

#include <QMessageBox>
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    socket(new QTcpSocket(this)),
    mainWindow(nullptr)  // 메인 윈도우를 위한 포인터 초기화
{
    ui->setupUi(this);

    // 로그인 버튼 클릭 시 연결 및 로그인 처리
    connect(ui->startButton, &QPushButton::clicked, this, &Widget::onLoginButtonClicked);

    // 닫기 버튼 클릭 시 프로그램 종료
    connect(ui->CloseButton, &QPushButton::clicked, this, &Widget::onCloseButtonClicked);

    // 서버로부터 메시지를 수신할 때 처리
    connect(socket, &QTcpSocket::readyRead, this, &Widget::receiveLoginResponse);
}

Widget::~Widget()
{
    delete ui;
    if (mainWindow != nullptr) {
        delete mainWindow;
    }
}

void Widget::onLoginButtonClicked()
{
    if (socket->state() != QTcpSocket::ConnectedState) {
        // 서버 주소와 포트 가져오기
        QString serverAddress = ui->ipLineEdit->text();
        quint16 serverPort = ui->portLineEdit->text().toUShort();

        // 서버에 연결 시도
        socket->connectToHost(QHostAddress(serverAddress), serverPort);

        if (!socket->waitForConnected(3000)) {
            QMessageBox::critical(this, "연결 실패", "서버에 연결할 수 없습니다.");
            return;
        }
    }

    QString username = ui->userLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "사용자 이름과 비밀번호를 입력해주세요.");
        return;
    }

    // 서버로 로그인 정보 전송
    QString loginRequest = "USER_LOGIN:" + username + ":" + password + "\n";
    socket->write(loginRequest.toUtf8());
    socket->flush();
}

void Widget::receiveLoginResponse()
{
    while (socket->canReadLine()) {
        QString response = socket->readLine().trimmed();

        if (response == "LOGIN_SUCCESS") {
            QMessageBox::information(this, "로그인 성공", "로그인에 성공했습니다!");

            QString serverAddress = ui->ipLineEdit->text();
            quint16 serverPort = ui->portLineEdit->text().toUShort();
            ServerInfo::getInstance().setServerInfo(serverAddress, serverPort);

            // 메인 윈도우가 nullptr이면 새로 생성
            if (mainWindow == nullptr) {
                mainWindow = new MainWindow();  // 매개변수가 있는 생성자가 있다면 그에 맞게 수정
            }

            mainWindow->show();  // 메인 윈도우 표시
            this->close();  // 로그인 창 닫기
        }
        else if (response == "ACCOUNT_CREATED") {
            QMessageBox::information(this, "계정 생성", "새 계정이 생성되었습니다. 로그인에 성공했습니다!");

            // 메인 윈도우가 nullptr이면 새로 생성
            if (mainWindow == nullptr) {
                mainWindow = new MainWindow();  // 매개변수가 있는 생성자가 있다면 그에 맞게 수정
            }

            mainWindow->show();  // 메인 윈도우 표시
            this->close();  // 로그인 창 닫기
        }
        else if (response == "LOGIN_FAILURE") {
            QMessageBox::warning(this, "로그인 실패", "사용자 이름 또는 비밀번호가 잘못되었습니다.");
        }
    }
}

void Widget::onCloseButtonClicked()
{
    QApplication::quit();  // 애플리케이션 종료
}
