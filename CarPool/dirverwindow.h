#ifndef DIRVERWINDOW_H
#define DIRVERWINDOW_H

#include <QMainWindow>

namespace Ui {
class DirverWindow;
}

class DirverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DirverWindow(QWidget *parent = nullptr);
    ~DirverWindow();

private:
    Ui::DirverWindow *ui;
};

#endif // DIRVERWINDOW_H
