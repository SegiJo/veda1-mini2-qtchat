#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"

#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QMovie>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    // 스플래시 화면 설정

    QLabel *logoLabel = new QLabel(this);
    QPixmap logo(":/image/logo.png");  // 로고 이미지 경로 설정
    ui->logoLabel->setPixmap(logo);
    logoLabel->setAlignment(Qt::AlignCenter);  // 로고 중앙에 배치

    QLabel *splashLabel = new QLabel(this);
    QMovie *movie = new QMovie(":/image/loading_animation.gif");  // GIF 파일 경로 설정
    ui->splashLabel->setMovie(movie);
    splashLabel->setWindowFlags(Qt::FramelessWindowHint);
    splashLabel->setAlignment(Qt::AlignCenter);  // GIF를 중앙에 배치
    splashLabel->setGeometry(500, 250, 400, 300);  // 스플래시 창의 위치 및 크기 설정

    movie->start();  // GIF 애니메이션 시작
    splashLabel->show();  // 스플래시 화면 표시

    // 3초 후에 스플래시 화면을 닫고 본 창을 표시
    QTimer::singleShot(3000, [=]() {
        //splashLabel->close();
        LoginWindow *loginWindow = new LoginWindow(); // LoginWindow 생성
        loginWindow->show();  // 로그인 창을 보여줌
        this->close(); // MainWindow 닫기 (로그인 창을 먼저 보여주기 위해)
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}
