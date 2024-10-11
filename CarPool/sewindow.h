#ifndef SEWINDOW_H
#define SEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QtNetwork>
#include "ClickableLabel.h"

namespace Ui {
class SEWindow;
}

class SEWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SEWindow(QWidget *parent = nullptr);
    ~SEWindow();
private slots:
    void onBackButtonClicked();
    void onNewButtonClicked();
private:
    Ui::SEWindow *ui;
    QTcpSocket *socket;

    QPoint diff_pos;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // SEWINDOW_H
