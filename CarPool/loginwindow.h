#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QtNetwork>
#include "ClickableLabel.h"
#include "sewindow.h"
#include "chatlistwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void onCloseButtonClicked();
    void onLoginButtonClicked();    // 로그인 버튼 클릭 시 호출되는 함수
    void onRegisterButtonClicked();
    void receiveLoginResponse();    // 서버로부터 로그인 응답을 처리하는 함수


private:
    Ui::LoginWindow *ui;
    QTcpSocket *socket;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
       QPoint diff_pos;
};

#endif // LOGINWINDOW_H
