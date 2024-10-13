#include "chatroomwindow.h"
#include "ui_chatroomwindow.h"
#include "serverinfo.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QHostAddress>
#include "chatlistwindow.h"
#include <QTextStream>
#include <QTcpSocket>
#include <QFileDialog>
#include <QFileInfo>
#include <QPropertyAnimation>

ChatRoomWindow::ChatRoomWindow(const QString &roomName, QTcpSocket *socket, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ChatRoomWindow),
    socket(socket),
    roomName(roomName)
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

    // 페이드 인 애니메이션 추가
    QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(this, "windowOpacity");
    fadeInAnimation->setDuration(300);  // 애니메이션 지속 시간 (밀리초)
    fadeInAnimation->setStartValue(0.0); // 시작 값 (완전히 사라짐)
    fadeInAnimation->setEndValue(1.0);   // 끝 값 (완전히 보임)
    fadeInAnimation->start(); // 애니메이션 시작


    ui->SendButton->setEnabled(false); // 기본적으로 보내기 버튼 비활성화

    ui->roomNameLabel->setText(roomName);
    ui->roomNameLabel->setText(roomName);
    this->setWindowTitle(roomName + " - 채팅방");


    emoticons << "😎" << "🥺" << "🤣" << "👊🏻" << "🩵"; // 필요에 따라 이모티콘 추가

    // 서버에 전달된 IP와 포트 번호를 가져옴
    QString serverAddress = ServerInfo::getInstance().getServerAddress();
    quint16 serverPort = ServerInfo::getInstance().getServerPort();

    // 서버에 연결
    setupConnection(serverAddress, serverPort);

    connect(ui->SendButton, &QPushButton::clicked, this, &ChatRoomWindow::onSendButtonclicked);
    connect(ui->MessageInput, &QTextEdit::textChanged, [=]() {
        if (ui->MessageInput->toPlainText().length() >= 1 && ui->MessageInput->toPlainText().length() <= 200) {
            ui->SendButton->setEnabled(true); // 버튼 활성화
        } else {
            ui->SendButton->setEnabled(false); // 버튼 비활성화
        }
    });
    connect(socket, &QTcpSocket::readyRead, this, &ChatRoomWindow::onReceiveMessage);
    connect(ui->NameButton, &QPushButton::clicked, this, &ChatRoomWindow::onNameSetting);
    connect(ui->BackButton, &QPushButton::clicked, this, &ChatRoomWindow::onCloseButtonclicked);
    connect(ui->SendFileButton, &QPushButton::clicked, this, &ChatRoomWindow::onSendFileButtonClicked);
    connect(ui->EmoticonButton, &QPushButton::clicked, this, &ChatRoomWindow::onemoticonButtonClicked);
}

ChatRoomWindow::~ChatRoomWindow()
{
    delete ui;
}

/*
void ChatRoomWindow::refreshUserList()
{
    // 서버에서 채팅방 멤버 목록 가져오기
    QByteArray request = "USER_LIST:" + roomName.toUtf8() + "\n";
    socket->write(request);
}

void ChatRoomWindow::refreshChat()
{
    // 서버에서 최신 채팅 기록 가져오기
    QByteArray request = "GET_MESSAGES:" + roomName.toUtf8() + ":" + QString::number(latestMessageID).toUtf8() + "\n";
    socket->write(request);
}
*/

void ChatRoomWindow::setupConnection(const QString &serverAddress, quint16 serverPort)
{
    // ServerInfo에서 가져온 IP 주소와 포트로 연결
    socket->connectToHost(serverAddress, serverPort);

    connect(socket, &QTcpSocket::connected, this, &ChatRoomWindow::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ChatRoomWindow::onDisconnected);

    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "연결 실패", "서버에 연결할 수 없습니다.");
    }
}
void ChatRoomWindow::onSendButtonclicked()
{
    // 입력된 메시지 가져오기
    QString message = ui->MessageInput->toPlainText();

    if (message.isEmpty()) {
        QMessageBox::warning(this, "메시지 오류", "메시지를 입력하세요.");
        return;
    }

    // 서버로 메시지 전송
    socket->write(QString("MSG:" + message + "\n").toUtf8());

    // 전송 후 메시지 창 비우기
    ui->MessageInput->clear();
}


void ChatRoomWindow::onSendFileButtonClicked()
{
    // 파일 선택 대화상자 열기
    QString fileName = QFileDialog::getOpenFileName(this, tr("파일 선택"), "", tr("모든 파일 (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray fileData = file.readAll(); // 파일 내용을 읽어옴
            file.close();

            // 파일 전송 메시지 형식에 맞춰서 서버로 전송
            socket->write(QString("FILE:" + QFileInfo(file).fileName() + "\n").toUtf8());
            socket->write(fileData); // 파일 데이터 전송
            socket->write("\n"); // 파일 전송 종료를 알리기 위해 개행 문자 전송

            // 메시지 브라우저에 파일 전송 완료 메시지 추가
            ui->messageBrowser->append("파일 전송 완료: " + QFileInfo(file).fileName());

            // 이미지 파일인 경우, 이미지 추가
            QString fileSuffix = QFileInfo(file).suffix().toLower(); // 파일 확장자 가져오기
            if (fileSuffix == "png" || fileSuffix == "jpg" || fileSuffix == "jpeg" || fileSuffix == "bmp" || fileSuffix == "gif") {
                // 이미지 태그 생성
                QString html = QString("<img src=\"file:///%1\" width=\"200\" height=\"200\"/>").arg(fileName);
                ui->messageBrowser->append(html); // 이미지 표시
            }
        } else {
            QMessageBox::warning(this, "파일 오류", "파일을 열 수 없습니다.");
        }
    }
}

void ChatRoomWindow::onemoticonButtonClicked() {
    // 이모티콘 선택 다이얼로그 열기
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    // 이모티콘 버튼 추가
    for (const QString &emoticon : emoticons) {
        QPushButton *button = new QPushButton(emoticon, dialog);
        connect(button, &QPushButton::clicked, [this, emoticon]() {
            ui->MessageInput->insertPlainText(emoticon); // 메시지 입력에 이모티콘 추가
        });
        layout->addWidget(button);
    }
    dialog->exec();
}


void ChatRoomWindow::onReceiveMessage()
{
    while (socket->canReadLine()) {
        QString message = QString::fromUtf8(socket->readLine()).trimmed();
        ui->messageBrowser->append(message);  // 메시지를 텍스트 브라우저에 출력
    }
}
void ChatRoomWindow::onConnected()
{
    ui->messageBrowser->append("서버에 연결되었습니다.");
}

void ChatRoomWindow::onDisconnected()
{
    ui->messageBrowser->append("서버와의 연결이 끊겼습니다.");
}

void ChatRoomWindow::onNameSetting()
{
    QString name = ui->nameLineEdit->text();
    socket->write(QString("NICKNAME:" + name + "\n").toUtf8());

    QMessageBox::information(this, "닉네임 설정", "닉네임이 변경되었습니다!");
}

void ChatRoomWindow::onCloseButtonclicked()
{
    QPropertyAnimation *fadeOutAnimation = new QPropertyAnimation(this, "windowOpacity");
    fadeOutAnimation->setDuration(300);
    fadeOutAnimation->setStartValue(1.0); // 현재 보임
    fadeOutAnimation->setEndValue(0.0);   // 완전히 사라짐
    fadeOutAnimation->start();

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
