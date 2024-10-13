#include "sewindow.h"
#include "ui_sewindow.h"
#include "chatlistwindow.h"
#include "serverinfo.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QPropertyAnimation>

SEWindow::SEWindow(QSqlDatabase database, QWidget *parent)
    : QMainWindow(parent),
      db(database),
     ui(new Ui::SEWindow)
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


    connect(ui->NewButton, &QPushButton::clicked, this, &SEWindow::onNewButtonClicked);
    connect(ui->BackButton, &QPushButton::clicked, this, &SEWindow::onBackButtonClicked);
}

SEWindow::~SEWindow()
{
    delete ui;
}

void SEWindow::onBackButtonClicked()
{
    if (parentWidget() != nullptr) {
        parentWidget()->show();
    }
    this->close();  // SEWindow 닫기
}

void SEWindow::onNewButtonClicked()
{
    QString roomName = ui->ChatNameInput->text().trimmed();
    QString startName = ui->StartInput->text().trimmed();
    QString endName = ui->FinishInput->text().trimmed();

    if (roomName.isEmpty() || startName.isEmpty() || endName.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "빈 필드에 모두 입력해주세요.");
        return;
    }

    QTcpSocket *socket = new QTcpSocket(this);

    // 서버 IP 주소와 포트 번호
    QString serverAddress = ServerInfo::getInstance().getServerAddress();
    quint16 serverPort = ServerInfo::getInstance().getServerPort();

    socket->connectToHost(serverAddress, serverPort);

    // 연결 대기 (최대 3초)
    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "연결 오류", "서버에 연결할 수 없습니다.");
        return;
    }

    // 서버로 검색어와 컬럼을 전송
    QString addRequest = QString("ADDCHATROOM_TABLE:%1:%2:%3").arg(roomName).arg(startName).arg(endName);
    socket->write(addRequest.toUtf8());
    socket->flush();

    QMessageBox::information(this, "성공", "채팅방이 생성되었습니다.");

    this->close();

}

void SEWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void SEWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}
