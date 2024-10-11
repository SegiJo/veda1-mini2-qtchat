#ifndef CARPOOLMAINWINDOW_H
#define CARPOOLMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CarpoolMainWindow;
}

class CarpoolMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarpoolMainWindow(QWidget *parent = nullptr);
    ~CarpoolMainWindow();

private:
    Ui::CarpoolMainWindow *ui;
};

#endif // CARPOOLMAINWINDOW_H
