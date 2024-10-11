/********************************************************************************
** Form generated from reading UI file 'carpoolmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARPOOLMAINWINDOW_H
#define UI_CARPOOLMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarpoolMainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *DirverButton;
    QLabel *PassengerButton;

    void setupUi(QMainWindow *CarpoolMainWindow)
    {
        if (CarpoolMainWindow->objectName().isEmpty())
            CarpoolMainWindow->setObjectName("CarpoolMainWindow");
        CarpoolMainWindow->resize(554, 402);
        centralwidget = new QWidget(CarpoolMainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 30, 451, 341));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        DirverButton = new QLabel(frame);
        DirverButton->setObjectName("DirverButton");
        DirverButton->setGeometry(QRect(70, 100, 100, 100));
        DirverButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 2px solid #424242;\n"
"border-radius: 50px;\n"
"cursor: pointer;\n"
"\n"
"QLabel::hover {\n"
"     background-color: rgba(66, 66, 66, 0.1); \n"
" }"));
        DirverButton->setPixmap(QPixmap(QString::fromUtf8(":/image/car.png")));
        DirverButton->setScaledContents(true);
        PassengerButton = new QLabel(frame);
        PassengerButton->setObjectName("PassengerButton");
        PassengerButton->setGeometry(QRect(280, 100, 100, 100));
        PassengerButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 2px solid #424242;\n"
"border-radius: 50px;\n"
"cursor: pointer;\n"
"\n"
"QLabel::hover {\n"
"     background-color: rgba(66, 66, 66, 0.1); \n"
" }"));
        PassengerButton->setPixmap(QPixmap(QString::fromUtf8(":/image/peple.png")));
        PassengerButton->setScaledContents(true);
        CarpoolMainWindow->setCentralWidget(centralwidget);

        retranslateUi(CarpoolMainWindow);

        QMetaObject::connectSlotsByName(CarpoolMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CarpoolMainWindow)
    {
        CarpoolMainWindow->setWindowTitle(QCoreApplication::translate("CarpoolMainWindow", "MainWindow", nullptr));
        DirverButton->setText(QString());
        PassengerButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CarpoolMainWindow: public Ui_CarpoolMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARPOOLMAINWINDOW_H
