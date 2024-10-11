#include "sewindow.h"
#include "ui_sewindow.h"
#include "chatlistwindow.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

SEWindow::SEWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SEWindow)
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
    QString chatname = ui->ChatNameInput->text().trimmed();
    QString start = ui->StartInput->text().trimmed();
    QString finish = ui->FinishInput->text().trimmed();

    // 필수 입력 값이 비어 있는지 확인
    if (chatname.isEmpty() || start.isEmpty() || finish.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "모든 필드를 입력해주세요.");
        return;
    }

    QString creatorName = "DefaultCreator";  // 생성자 이름 (필요시 입력 받도록 수정 가능)

    // 서버로 채팅방 생성 요청 보내기
    QByteArray request;
    request.append("ADD_CHATROOM|");
    request.append(chatname.toUtf8() + "|" + start.toUtf8() + "|" + finish.toUtf8() + "|" + creatorName.toUtf8());

    socket->write(request);
    socket->flush();

    // 요청이 성공적으로 보내지면, 성공 메시지 출력 및 창 닫기
    QMessageBox::information(this, "정보", "채팅방 등록 요청이 전송되었습니다.");
    this->close();  // 창 닫기

}

void SEWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void SEWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}
