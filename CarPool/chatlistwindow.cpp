#include "chatlistwindow.h"
#include "ui_chatlistwindow.h"
#include "chatroomwindow.h"
#include "sewindow.h"
#include "loginwindow.h"
#include "serverinfo.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

#include <QStandardItemModel>

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QHostAddress>
#include <QPropertyAnimation>


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

    QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(this, "windowOpacity");
    fadeInAnimation->setDuration(300);  // 애니메이션 지속 시간 (밀리초)
    fadeInAnimation->setStartValue(0.0); // 시작 값 (완전히 사라짐)
    fadeInAnimation->setEndValue(1.0);   // 끝 값 (완전히 보임)
    fadeInAnimation->start(); // 애니메이션 시작

    // 시그널과 슬롯 연결
    //connect(ui->OpenChatButton, &QPushButton::clicked, this, &ChatListWindow::onOpenChatButtonclicked);
    connect(ui->JoinChatButton, &QPushButton::clicked, this, &ChatListWindow::onJoinButtonclicked);
    connect(ui->NewChatButton, &QPushButton::clicked, this, &ChatListWindow::onNewChatButtonclicked);
    connect(ui->FindChatButton, &QPushButton::clicked, this, &ChatListWindow::onFindChatButtonclicked);
    connect(ui->BackButton, &QPushButton::clicked, this, &ChatListWindow::onBackButtonclicked);

}
ChatListWindow::ChatListWindow(QSqlDatabase database, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ChatListWindow),
    db(database),
    chatroommodel(new QSqlQueryModel(this))
{
     ui->setupUi(this);

    connect(ui->JoinChatButton, &QPushButton::clicked, this, &ChatListWindow::onJoinButtonclicked);
    connect(ui->NewChatButton, &QPushButton::clicked, this, &ChatListWindow::onNewChatButtonclicked);
    connect(ui->FindChatButton, &QPushButton::clicked, this, &ChatListWindow::onFindChatButtonclicked);
    connect(ui->BackButton, &QPushButton::clicked, this, &ChatListWindow::onBackButtonclicked);

}

ChatListWindow::~ChatListWindow()
{
    delete ui;
}

void ChatListWindow::onJoinButtonclicked() {

    QModelIndex selectedIndex = ui->JoinChatListtableView->currentIndex();
    if (!selectedIndex.isValid()) {
        QMessageBox::warning(this, "선택 오류", "참가할 채팅방을 선택해주세요.");
        return;
    }

    QString selectedRoomName = ui->JoinChatListtableView->model()->data(ui->JoinChatListtableView->model()->index(selectedIndex.row(), 0)).toString();
    qDebug() << "선택된 채팅방: " << selectedRoomName;

    // 서버로 참가 요청
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ServerInfo::getInstance().getServerAddress(), ServerInfo::getInstance().getServerPort());

    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "연결 오류", "서버에 연결할 수 없습니다.");
        return;
    }

    // JOIN_CHATROOM 요청 전송
    socket->write(QString("JOIN_CHATROOM:" + selectedRoomName + "\n").toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QByteArray response = socket->readAll();
        QString responseString(response);

        // 서버로부터 응답 데이터를 받음
        QByteArray responseData = socket->readAll();
        qDebug() << "서버로부터 받은 데이터: " << responseData;

        QStringList chatRooms = QString(responseData).split("\n", Qt::SkipEmptyParts);

        if (responseString.contains("JOIN_SUCCESS")) {
            qDebug() << "채팅방에 성공적으로 참가했습니다.";

            ChatRoomWindow *chatWindow = new ChatRoomWindow(selectedRoomName, socket, nullptr);  // 부모를 nullptr로 설정하여 독립된 창으로 띄움
            chatWindow->setAttribute(Qt::WA_DeleteOnClose);  // 창이 닫힐 때 메모리 자동 해제
            chatWindow->show();
        } else {
            qDebug() << "채팅방 참가 실패";
            QMessageBox::warning(this, "참가 오류", "채팅방 참가에 실패했습니다.");
        }
    }
}

void ChatListWindow::onNewChatButtonclicked() {

   SEWindow *newChatWindow = new SEWindow(db, this);

    // SEWindow의 기존 설정에 추가적인 UI 설정은 필요 없음
    newChatWindow->setWindowFlags(newChatWindow->windowFlags() | Qt::Window);  // 독립적인 창으로 설정
    newChatWindow->show();

    qDebug() << "새 채팅방 추가 버튼이 클릭되었습니다.";
}

void ChatListWindow::onFindChatButtonclicked() {
    qDebug() << "검색 버튼이 클릭되었습니다.";
    // 검색 로직을 여기에서 구현
    QString searchTerm = ui->ChatNameInput->text().trimmed();

    if (searchTerm.isEmpty()) {
        // 검색어가 없으면 모든 채팅방 표시
        //loadAllChatRooms();
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

    QString column = "room_name"; // 여기서 검색할 컬럼을 선택합니다.

    // 서버로 검색어와 컬럼을 전송
    QString searchRequest = QString("SEARCH:%1:%2").arg(column).arg(searchTerm);
    socket->write(searchRequest.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QByteArray responseData = socket->readAll();
        QStringList chatRooms = QString(responseData).split("\n", Qt::SkipEmptyParts);

        // 검색 결과를 UI에 표시
        QStandardItemModel *model = new QStandardItemModel(chatRooms.size(), 3, this);
        model->setHeaderData(0, Qt::Horizontal, "Room Name");
        model->setHeaderData(1, Qt::Horizontal, "Start Place");
        model->setHeaderData(2, Qt::Horizontal, "End Place");

        for (int i = 0; i < chatRooms.size(); ++i) {
            QStringList roomData = chatRooms[i].split(",");
            if (roomData.size() == 3) {
                model->setItem(i, 0, new QStandardItem(roomData[0]));  // room_name
                model->setItem(i, 1, new QStandardItem(roomData[1]));  // start_place
                model->setItem(i, 2, new QStandardItem(roomData[2]));  // end_place
            }
        }

        ui->JoinChatListtableView->setModel(model);
        ui->JoinChatListtableView->resizeColumnsToContents();

        // 첫 번째 열은 고정, 두 번째와 세 번째 열은 부모 위젯에 맞춰 자동 확장
        ui->JoinChatListtableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);  // 첫 번째 열 고정
        ui->JoinChatListtableView->setColumnWidth(0, 150);  // 첫 번째 열의 고정 크기 설정
        ui->JoinChatListtableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);  // 두 번째 열 확장
        ui->JoinChatListtableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);  // 세 번째 열 확장
    } else {
        QMessageBox::warning(this, "검색 오류", "검색 결과를 서버로부터 받을 수 없습니다.");
    }
}


void ChatListWindow::loadAllChatRooms()
{
    qDebug() << "채팅방 목록을 서버로부터 불러옵니다.";

    // 서버에 연결하여 데이터를 받아오기 위해 QTcpSocket을 사용
    QTcpSocket *socket = new QTcpSocket(this);

    // 서버 IP 주소와 포트 번호
    QString serverAddress = ServerInfo::getInstance().getServerAddress();
    quint16 serverPort = ServerInfo::getInstance().getServerPort();

    socket->connectToHost(serverAddress, serverPort);

    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "연결 오류", "서버에 연결할 수 없습니다.");
        return;
    }

    // 서버로부터 채팅방 데이터를 요청
    socket->write("GET_CHATROOMS\n");
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        QMessageBox::warning(this, "데이터 수신 오류", "서버로부터 데이터를 받을 수 없습니다.");
        return;
    }

    // 서버로부터 응답 데이터를 받음
    QByteArray responseData = socket->readAll();
    QStringList chatRooms = QString(responseData).split("\n", Qt::SkipEmptyParts);

    // QStandardItemModel을 사용하여 데이터를 테이블에 추가
    QStandardItemModel *model = new QStandardItemModel(chatRooms.size(), 3, this);
    model->setHeaderData(0, Qt::Horizontal, "Room Name");
    model->setHeaderData(1, Qt::Horizontal, "Start Place");
    model->setHeaderData(2, Qt::Horizontal, "End Place");

    // 서버로부터 받은 데이터를 테이블에 채우기
    for (int i = 0; i < chatRooms.size(); ++i) {
        QStringList roomData = chatRooms[i].split(",");
           qDebug() << "룸 데이터: " << roomData;
        if (roomData.size() == 3) {
            model->setItem(i, 0, new QStandardItem(roomData[0]));  // room_name
            model->setItem(i, 1, new QStandardItem(roomData[1]));  // start_place
            model->setItem(i, 2, new QStandardItem(roomData[2]));  // end_place
        }
    }

    // 테이블 뷰에 모델 설정
    ui->JoinChatListtableView->setModel(model);

    // 테이블 뷰 열 크기 조정
    ui->JoinChatListtableView->resizeColumnsToContents();

    // 첫 번째 열은 고정, 두 번째와 세 번째 열은 부모 위젯에 맞춰 자동 확장
    ui->JoinChatListtableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);  // 첫 번째 열 고정
    ui->JoinChatListtableView->setColumnWidth(0, 150);  // 첫 번째 열의 고정 크기 설정
    ui->JoinChatListtableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);  // 두 번째 열 확장
    ui->JoinChatListtableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);  // 세 번째 열 확장
}



void ChatListWindow::onBackButtonclicked() {

    QPropertyAnimation *fadeOutAnimation = new QPropertyAnimation(this, "windowOpacity");
    fadeOutAnimation->setDuration(300);
    fadeOutAnimation->setStartValue(1.0); // 현재 보임
    fadeOutAnimation->setEndValue(0.0);   // 완전히 사라짐
    fadeOutAnimation->start();

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
