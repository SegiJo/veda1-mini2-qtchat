#include "dirverwindow.h"
#include "ui_dirverwindow.h"

DirverWindow::DirverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DirverWindow)
{
    ui->setupUi(this);
}

DirverWindow::~DirverWindow()
{
    delete ui;
}
