#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QtNetwork>
#include "ClickableLabel.h"

namespace Ui {
class SignupWindow;
}

class SignupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignupWindow(QWidget *parent = nullptr);
    ~SignupWindow();

private slots:
    void onBackButtonClicked();
    void onRegisterButtonClicked();  // 등록 버튼 클릭 슬롯
    void onreceiveRegisterResponse();

private:
    Ui::SignupWindow *ui;
    QTcpSocket *socket;

    QPoint diff_pos;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // SIGNUPWINDOW_H
