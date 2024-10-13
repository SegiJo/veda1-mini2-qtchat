#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "serverinfo.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QCryptographicHash>  // 비밀번호 해시화에 필요한 헤더
#include <QPropertyAnimation>

SignupWindow::SignupWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignupWindow)
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
    connect(socket, &QTcpSocket::readyRead, this, &SignupWindow::onreceiveRegisterResponse);  // 서버 메시지 수신 처리

    connect(ui->RegisterButton, &QPushButton::clicked, this, &SignupWindow::onRegisterButtonClicked);
    connect(ui->BackButton, &QPushButton::clicked, this, &SignupWindow::onBackButtonClicked);
}

SignupWindow::~SignupWindow()
{
    delete ui;
}

void SignupWindow::onBackButtonClicked() {
    LoginWindow *loginWindow = new LoginWindow();  // 새로운 LoginWindow 생성
    loginWindow->show();  // 로그인 창을 보여줌
    this->close();  // 현재 SignupWindow 닫기
}

void SignupWindow::onRegisterButtonClicked()
{
        // 사용자 등록 처리
        QString username = ui->NameInput->text();
        QString password = ui->PasswdInput->text();

        // 사용자 이름과 비밀번호가 비어 있는지 확인
        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "입력 오류", "사용자 이름과 비밀번호를 입력해주세요.");
            return;
        }

        QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

        QString registerRequest = "USER_REGISTER:" + username + ":" + QString(hashedPassword) + "\n";
        socket->write(registerRequest.toUtf8());
        socket->flush();

}




void SignupWindow::onreceiveRegisterResponse()
{

    while (socket->canReadLine()) {
        QString response = socket->readLine().trimmed();
        qDebug() << "Received from server:" << response;

        // 서버와 연결 후 사용자 등록 요청 전송
        if (socket->state() == QAbstractSocket::ConnectedState) {
            // 서버 응답 대기
            if (socket->waitForReadyRead(3000)) {
                QByteArray response = socket->readAll();

                if (response == "REGISTER_SUCCESS") {
                    QMessageBox::information(this, "등록 성공", "계정이 성공적으로 등록되었습니다.");
                    this->close();  // 등록 후 창 닫기
                } else if (response == "REGISTER_FAILURE") {
                    QMessageBox::critical(this, "등록 실패", "계정 등록에 실패했습니다.");
                }
            }
        } else {
            QMessageBox::warning(this, "서버 연결 오류", "서버에 연결되어 있지 않습니다.");
        }
    }
}


void SignupWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void SignupWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}

