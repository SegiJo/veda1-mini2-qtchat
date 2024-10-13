#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "signupwindow.h"
#include "sewindow.h"
#include "chatlistwindow.h"
#include "serverinfo.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QHostAddress>
#include <QDialog>
#include <QCryptographicHash>
#include <QPropertyAnimation>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    // UI 설정 및 효과
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect * shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setOffset(0, 0);
    QColor color = Qt::black;
    color.setAlpha(64);
    shadowEffect->setColor(color);
    shadowEffect->setBlurRadius(20);
    ui->frame->setGraphicsEffect(shadowEffect);

    QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(this, "windowOpacity");
    fadeInAnimation->setDuration(300);  // 애니메이션 지속 시간 (밀리초)
    fadeInAnimation->setStartValue(0.0); // 시작 값 (완전히 사라짐)
    fadeInAnimation->setEndValue(1.0);   // 끝 값 (완전히 보임)
    fadeInAnimation->start(); // 애니메이션 시작


    // 소켓 초기화
    socket = new QTcpSocket(this);  // 소켓 객체를 초기화
    connect(socket, &QTcpSocket::readyRead, this, &LoginWindow::receiveLoginResponse);  // 서버 메시지 수신 처리

    // 시그널과 슬롯 연결
    ClickableLabel* registerLabel = qobject_cast<ClickableLabel*>(ui->RegisterButton);
    connect(registerLabel, &ClickableLabel::clicked, this, &LoginWindow::onRegisterButtonClicked);
    connect(ui->LoginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(ui->CloseButton, &QPushButton::clicked, this, &LoginWindow::onCloseButtonClicked);

}


LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onRegisterButtonClicked() {

    SignupWindow *signupwindow = new SignupWindow(); // 새로운 SignupWindow 생성
    signupwindow->show();  // SignupWindow를 보여줌
    this->close(); // 현재 LoginWindow 닫기

}

void LoginWindow::onLoginButtonClicked()
{
    if (socket->state() != QTcpSocket::ConnectedState) {
        // 서버 주소와 포트 가져오기
        QString serverAddress = ui->IpInput->text();
        quint16 serverPort = ui->PortInput->text().toUShort();

        // 서버에 연결 시도
        socket->connectToHost(QHostAddress(serverAddress), serverPort);

        if (!socket->waitForConnected(3000)) {
            QMessageBox::critical(this, "연결 실패", "서버에 연결할 수 없습니다.");
            return;
        }
    }

    QString username = ui->NameInput->text();
    QString password = ui->PasswdInput->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "사용자 이름과 비밀번호를 입력해주세요.");
        return;
    }

    // 서버로 로그인 정보 전송
    QString loginRequest = "USER_LOGIN:" + username + ":" + password + "\n";
    socket->write(loginRequest.toUtf8());
    socket->flush();
   /*
    ChatListWindow *userChatList = new ChatListWindow();
    userChatList->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed
    userChatList->show();  // Show the chat list window
    this->close();
*/
}

void LoginWindow::receiveLoginResponse() {
    while (socket->canReadLine()) {
        QString response = socket->readLine().trimmed();
        ChatListWindow *userChatList = new ChatListWindow();

        if (response == "LOGIN_SUCCESS") {
            QMessageBox::information(this, "로그인 성공", "로그인에 성공했습니다!");

            QString serverAddress = ui->IpInput->text();
            quint16 serverPort = ui->PortInput->text().toUShort();
            ServerInfo::getInstance().setServerInfo(serverAddress, serverPort);

            userChatList->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed
            userChatList->show();  // Show the chat list window
            this->close();
        }
        else if (response == "ACCOUNT_CREATED") {
            QMessageBox::information(this, "계정 생성", "새 계정이 생성되었습니다. 로그인에 성공했습니다!");

            userChatList->show();  // Show the chat list window
            this->close();  // 로그인 창 닫기
        }
        else if (response == "LOGIN_FAILURE") {
            QMessageBox::warning(this, "로그인 실패", "사용자 이름 또는 비밀번호가 잘못되었습니다.");
        }
    }
}


void LoginWindow::onCloseButtonClicked()
{
    this->close();
}

void LoginWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void LoginWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}

