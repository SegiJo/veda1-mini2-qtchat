#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "loginwindow.h"
#include "mainwindow.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QCryptographicHash>  // 비밀번호 해시화에 필요한 헤더
#include <QTcpSocket>

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

    socket = new QTcpSocket(this);  // 소켓 객체를 초기화

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

    QString username = ui->NameInput->text();  // 사용자 이름 입력
    QString password = ui->PasswdInput->text();  // 비밀번호 입력

    // 사용자 이름과 비밀번호가 비어 있는지 확인
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "사용자 이름과 비밀번호를 입력해주세요.");
        return;
    }

    // 비밀번호 해시화 (SHA-256)
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    if (socket->state() == QAbstractSocket::ConnectedState) {
        // 서버로 등록 요청 전송
        QString registerRequest = "USER_REGISTER:" + username + ":" + QString(hashedPassword) + "\n";
        socket->write(registerRequest.toUtf8());  // 서버로 데이터 전송
        socket->flush();
    } else {
        QMessageBox::warning(this, "서버 연결 오류", "서버에 연결되어 있지 않습니다.");
    }
    // 서버 응답 대기
    if (socket->waitForReadyRead(3000)) {  // 3초 동안 서버 응답 대기
        QByteArray response = socket->readAll();  // 서버로부터 응답 받기
        QString responseString = QString::fromUtf8(response).trimmed();  // 응답을 문자열로 변환

        if (responseString == "REGISTER_SUCCESS") {
            QMessageBox::information(this, "등록 성공", "계정이 성공적으로 등록되었습니다.");
            this->close();  // 등록 성공 후 창 닫기
        } else if (responseString == "REGISTER_FAILURE") {
            QMessageBox::critical(this, "등록 실패", "계정 등록에 실패했습니다.");
        }
    } else {
        QMessageBox::critical(this, "서버 오류", "서버 응답이 없습니다. 나중에 다시 시도해주세요.");
    }
}

void SignupWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) { // 왼쪽 버튼 클릭일 때만 처리
        diff_pos = this->pos() - event->globalPos();
    }
}

void SignupWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) { // 왼쪽 버튼이 눌린 상태에서만 이동
        this->move(event->globalPos() + diff_pos);
    }
}
