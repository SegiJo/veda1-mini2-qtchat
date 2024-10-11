#include "passengerwindow.h"
#include "ui_passengerwindow.h"

PassengerWindow::PassengerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PassengerWindow)
{
    ui->setupUi(this);
}

PassengerWindow::~PassengerWindow()
{
    delete ui;
}
