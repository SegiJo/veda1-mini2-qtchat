#ifndef PASSENGERWINDOW_H
#define PASSENGERWINDOW_H

#include <QMainWindow>

namespace Ui {
class PassengerWindow;
}

class PassengerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassengerWindow(QWidget *parent = nullptr);
    ~PassengerWindow();

private:
    Ui::PassengerWindow *ui;
};

#endif // PASSENGERWINDOW_H
