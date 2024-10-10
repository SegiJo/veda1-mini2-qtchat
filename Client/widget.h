#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include "mainwindow.h"  // MainWindow 포함

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onLoginButtonClicked();    // 로그인 버튼 클릭 시 호출되는 함수
    void onCloseButtonClicked();    // 닫기 버튼 클릭 시 호출되는 함수
    void receiveLoginResponse();    // 서버로부터 로그인 응답을 처리하는 함수

private:
    Ui::Widget *ui;                 // UI 클래스
    QTcpSocket *socket;             // 서버와의 연결 소켓
    MainWindow *mainWindow;         // MainWindow 객체 포인터
};

#endif // WIDGET_H
