#include "chat.h"
#include "ui_chat.h"
#include "serverinfo.h"

#include <QMessageBox>
#include <QTextStream>

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    // 서버에 전달된 IP와 포트 번호를 가져옴
    QString serverAddress = ServerInfo::getInstance().getServerAddress();
    quint16 serverPort = ServerInfo::getInstance().getServerPort();

    // 서버에 연결
    setupConnection(serverAddress, serverPort);

    // 메시지 전송 버튼 클릭 시 메시지 전송
    connect(ui->sendButton, &QPushButton::clicked, this, &Chat::onSendMessage);
    // 소켓에서 메시지를 읽을 준비가 되면 onReceiveMessage 호출
    connect(socket, &QTcpSocket::readyRead, this, &Chat::onReceiveMessage);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::setupConnection(const QString &serverAddress, quint16 serverPort)
{
    // ServerInfo에서 가져온 IP 주소와 포트로 연결
    socket->connectToHost(serverAddress, serverPort);

    connect(socket, &QTcpSocket::connected, this, &Chat::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Chat::onDisconnected);

    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "연결 실패", "서버에 연결할 수 없습니다.");
    }
}

void Chat::onSendMessage()
{
    QString message = ui->messageTextEdit->toPlainText().trimmed();
    if (message.isEmpty()) {
        QMessageBox::warning(this, "메시지 오류", "메시지를 입력하세요.");
        return;
    }

    // 서버로 메시지 전송
    socket->write(QString("MSG:" + message + "\n").toUtf8());

    // 전송 후 메시지 창 비우기
    ui->messageTextEdit->clear();
}

void Chat::onReceiveMessage()
{
    while (socket->canReadLine()) {
        QString message = QString::fromUtf8(socket->readLine()).trimmed();
        ui->messageBrowser->append(message);  // 메시지를 텍스트 브라우저에 출력
    }
}

void Chat::onConnected()
{
    ui->messageBrowser->append("서버에 연결되었습니다.");
}

void Chat::onDisconnected()
{
    ui->messageBrowser->append("서버와의 연결이 끊겼습니다.");
}
