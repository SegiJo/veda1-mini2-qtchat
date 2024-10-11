#include "carpoolmainwindow.h"
#include "ui_carpoolmainwindow.h"

CarpoolMainWindow::CarpoolMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CarpoolMainWindow)
{
    ui->setupUi(this);
}

CarpoolMainWindow::~CarpoolMainWindow()
{
    delete ui;
}
