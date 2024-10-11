#include "chatroomwindow.h"
#include "ui_chatroomwindow.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QHostAddress>
#include "chatlistwindow.h"
#include "clientcore.h"
#include <QTcpSocket>

ChatRoomWindow::ChatRoomWindow(const QString &chatName, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ChatRoomWindow),
    currentChatName(chatName), // 현재 채팅 이름 설정
    latestMessageID(0),
    lastTime("yyyy-MM-dd hh:mm:ss"),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false); // 창 닫을 때 프로그램 종료하지 않음
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    // UI 그림자 효과 설정
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setOffset(0, 0);
    QColor color = Qt::black;
    color.setAlpha(64);
    shadowEffect->setColor(color);
    shadowEffect->setBlurRadius(20);
    ui->frame->setGraphicsEffect(shadowEffect);

    ui->SendButton->setEnabled(false); // 기본적으로 보내기 버튼 비활성화

    connect(ui->MessageInput, &QTextEdit::textChanged, [=]() {
        if (ui->MessageInput->toPlainText().length() >= 1 && ui->MessageInput->toPlainText().length() <= 200) {
            ui->SendButton->setEnabled(true); // 버튼 활성화
        } else {
            ui->SendButton->setEnabled(false); // 버튼 비활성화
        }
    });

    latestMessageID = 0; // 최신 메시지 ID 초기화
    lastTime = "yyyy-MM-dd hh:mm:ss"; // 마지막 시간 초기화

    refreshUserList(); // 사용자 목록 새로 고침
    refreshChat(); // 채팅 내용 새로 고침

    // 매 초마다 채팅 기록을 새로 고침
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ChatRoomWindow::refreshChat);
    timer->start(1000); // 1초마다 실행

    // 매 5초마다 채팅방 멤버 목록을 새로 고침
    QTimer *timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &ChatRoomWindow::refreshUserList);
    timer2->start(5000); // 5초마다 실행

    // 서버와 연결
    //socket->connectToHost(QHostAddress(serverAddress), serverPort);  // 서버 IP와 포트 사용

    if (socket->waitForConnected(5000)) {  // 5초 동안 연결 대기
        connect(socket, &QTcpSocket::readyRead, this, &ChatRoomWindow::readyRead);
        qDebug() << "서버에 성공적으로 연결되었습니다.";
    } else {
        QString errorMessage = socket->errorString();  // 정확한 오류 메시지 출력
        QMessageBox::warning(this, "연결 실패", "서버와 연결할 수 없습니다: " + errorMessage);
        qDebug() << "연결 실패 이유: " << errorMessage;
    }
}

ChatRoomWindow::~ChatRoomWindow()
{
    delete ui;
    if (socket) {
        socket->disconnectFromHost();
        delete socket;
    }
}

void ChatRoomWindow::refreshUserList()
{
    // 서버에서 채팅방 멤버 목록 가져오기
    QByteArray request = "USER_LIST:" + currentChatName.toUtf8() + "\n";
    socket->write(request);
}

void ChatRoomWindow::refreshChat()
{
    // 서버에서 최신 채팅 기록 가져오기
    QByteArray request = "GET_MESSAGES:" + currentChatName.toUtf8() + ":" + QString::number(latestMessageID).toUtf8() + "\n";
    socket->write(request);
}

void ChatRoomWindow::readyRead()
{
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data).trimmed();

    if (message.startsWith("ME:")) {
        // 채팅 메시지 처리
        QStringList parts = message.split(":");
        if (parts.size() == 2) {
            QString userMessage = parts.at(1);
            chatHistory.append(userMessage);
            ui->textBrowser->setPlainText(chatHistory.join("\n"));
            ui->textBrowser->moveCursor(QTextCursor::End);
        }
    }
    else if (message.startsWith("USER_LIST:")) {
        // 사용자 목록 처리
        QStringList users = message.split(":").mid(1);
        // 사용자 목록 처리 코드 (예: ui에 사용자 표시)
    }
}

void ChatRoomWindow::onSendButtonclicked()
{
    // 입력된 메시지 가져오기
    QString message = ui->MessageInput->toPlainText();

    if (!message.isEmpty()) {
        // 메시지 전송
        QByteArray request = ":" + currentChatName.toUtf8() + ":" + message.toUtf8() + "\n";
        socket->write(request);
        ui->MessageInput->clear();
        refreshChat(); // 채팅 내용 새로 고침
    } else {
        QMessageBox::warning(this, "메시지 오류", "메시지를 입력해 주세요.");
    }
}

void ChatRoomWindow::onCloseButtonclicked()
{
    this->close();
}

void ChatRoomWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void ChatRoomWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}
