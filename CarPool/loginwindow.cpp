#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "signupwindow.h"
#include "sewindow.h"
#include "chatlistwindow.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QHostAddress>
#include <QDialog>
#include <QCryptographicHash>

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

    QString serverAddress = ui->IpInput->text();  // IP 입력 필드에서 값 가져오기
    quint16 serverPort = ui->PortInput->text().toUShort();  // 포트 입력 필드에서 값 가져오기

    // 서버와 연결
    socket->connectToHost(QHostAddress(serverAddress), serverPort);  // 서버 IP와 포트 사용

    if (!socket->waitForConnected(5000)) {  // 5초 동안 연결 대기
        QString errorMessage = socket->errorString();  // 정확한 오류 메시지 출력
        QMessageBox::warning(this, "연결 실패", "서버와 연결할 수 없습니다: " + errorMessage);
        qDebug() << "연결 실패 이유: " << errorMessage;
        return; // 연결 실패 시 함수를 종료
    }

    connect(socket, &QTcpSocket::readyRead, this, &LoginWindow::receiveLoginResponse);
    qDebug() << "서버에 성공적으로 연결되었습니다.";

    QString username = ui->NameInput->text();  // 사용자 이름 입력
    QString password = ui->PasswdInput->text(); // 비밀번호 입력

    // 입력 필드가 비어있는지 확인
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "사용자 이름과 비밀번호를 입력해주세요.");
        return;
    }

    // 비밀번호 해시화 (SHA-256)
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // 서버로 로그인 정보 전송
    QString loginRequest = "USER_LOGIN:" + username + ":" + QString(hashedPassword) + "\n";
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

        if (response == "LOGIN_SUCCESS") {
            QMessageBox::information(this, "로그인 성공", "로그인에 성공했습니다!");

            // 로그인 성공 시 ChatListWindow 띄우기
            ChatListWindow *chatlistwindow = new ChatListWindow(this);  // 부모를 지정하여 메모리 관리
            chatlistwindow->show();  // ChatListWindow 표시
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

