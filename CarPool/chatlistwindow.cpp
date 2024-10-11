#include "chatlistwindow.h"
#include "ui_chatlistwindow.h"
#include "chatroomwindow.h"
#include "sewindow.h"
#include "loginwindow.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QHostAddress>


ChatListWindow::ChatListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatListWindow)
{
    // UI 설정 및 효과
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect * shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setOffset(0, 0);
    QColor color = Qt::black;
    color.setAlpha(64);
    shadowEffect->setColor(color);
    shadowEffect->setBlurRadius(20);
    ui->frame->setGraphicsEffect(shadowEffect);

    socket = new QTcpSocket(this);  // TCP 소켓

    // 시그널과 슬롯 연결
    //connect(ui->OpenChatButton, &QPushButton::clicked, this, &ChatListWindow::onOpenChatButtonclicked);
    connect(ui->JoinChatButton, &QPushButton::clicked, this, &ChatListWindow::onJoinButtonclicked);
    connect(ui->NewChatButton, &QPushButton::clicked, this, &ChatListWindow::onNewChatButtonclicked);
    connect(ui->FindChatButton, &QPushButton::clicked, this, &ChatListWindow::onFindChatButtonclicked);
    connect(ui->BackButton, &QPushButton::clicked, this, &ChatListWindow::onBackButtonclicked);

    connect(socket, &QTcpSocket::readyRead, this, &ChatListWindow::receiveChatRoomList);  // 서버에서 채팅방 목록 수신
}

ChatListWindow::~ChatListWindow()
{
    delete ui;
}

void ChatListWindow::receiveChatRoomList()
{
    // 서버로부터 채팅방 목록을 수신
    while (socket->canReadLine()) {
        QByteArray response = socket->readLine().trimmed();
        QString chatRoomsString = QString::fromUtf8(response);

        QStringList chatRooms = chatRoomsString.split(',');
        ui->JoinChatListWidget->clear();
        ui->JoinChatListWidget->addItems(chatRooms);
    }
}

void ChatListWindow::onJoinButtonclicked() {

    if (ui->JoinChatListWidget->count() > 0 && ui->JoinChatListWidget->currentItem() != nullptr) {
        QString chatName = ui->JoinChatListWidget->currentItem()->text();

        // 채팅방 입장 요청을 서버로 전송
        QString joinRequest = "JOIN_CHATROOM:" + chatName + "\n";
        socket->write(joinRequest.toUtf8());
        socket->flush();

        // 채팅방 입장 요청을 성공적으로 전송한 후, ChatRoomWindow 창을 띄움
        ChatRoomWindow *chatRoomWindow = new ChatRoomWindow(chatName, this);  // 채팅방 이름을 전달
        chatRoomWindow->show();
        this->close();  // ChatListWindow를 닫고 새로운 채팅방 창으로 전환
    } else {
        QMessageBox::critical(this, "오류", "입장에 실패했습니다. 채팅방이 선택되었는지 확인해주세요.");
    }
}

void ChatListWindow::onNewChatButtonclicked() {
    SEWindow *newChatWindow = new SEWindow(this);

    // SEWindow의 기존 설정에 추가적인 UI 설정은 필요 없음
    newChatWindow->setWindowFlags(newChatWindow->windowFlags() | Qt::Window);  // 독립적인 창으로 설정
    newChatWindow->show();
}

void ChatListWindow::onFindChatButtonclicked() {
    findName = ui->ChatNameInput->text().trimmed();  // 입력된 채팅방 이름을 가져옴

    if (findName.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "검색할 채팅방 이름을 입력해주세요.");
        return;
    }

    // 서버에 검색 요청 전송
    QString searchRequest = "FIND_CHATROOM|" + findName + "\n";
    socket->write(searchRequest.toUtf8());
    socket->flush();
}

void ChatListWindow::receiveSearchResults()
{
    // 서버로부터 검색 결과 수신
    while (socket->canReadLine()) {
        QByteArray response = socket->readLine().trimmed();

        if (response.isEmpty()) {
            qWarning() << "검색 결과가 비어 있습니다.";
            return;
        }

        QString searchResults = QString::fromUtf8(response);
        QStringList chatRooms = searchResults.split(',');

        // 검색 결과를 리스트에 표시
        ui->JoinChatListWidget->clear();

        if (chatRooms.isEmpty()) {
            QMessageBox::information(this, "결과 없음", "검색 결과가 없습니다.");
        } else {
            foreach (const QString &chatRoom, chatRooms) {
                if (!chatRoom.isEmpty()) {
                    ui->JoinChatListWidget->addItem(chatRoom);
                }
            }
        }
    }
}

void ChatListWindow::onBackButtonclicked() {

    LoginWindow *loginWindow = new LoginWindow();  // 새로운 LoginWindow 생성
    loginWindow->show();  // 로그인 창을 보여줌
    this->close();

}

void ChatListWindow::mousePressEvent(QMouseEvent * event)
{
    diff_pos = this->pos()-event->globalPos();
}
void ChatListWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+diff_pos);
}
