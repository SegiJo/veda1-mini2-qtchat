/********************************************************************************
** Form generated from reading UI file 'passengerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERWINDOW_H
#define UI_PASSENGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PassengerWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *StartInput;
    QLineEdit *ArriveInput;
    QPushButton *ListButton;

    void setupUi(QMainWindow *PassengerWindow)
    {
        if (PassengerWindow->objectName().isEmpty())
            PassengerWindow->setObjectName("PassengerWindow");
        PassengerWindow->resize(554, 402);
        centralwidget = new QWidget(PassengerWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 30, 451, 341));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 40, 40, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/pin.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 40, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/pin.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 55, 51, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 140, 51, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        StartInput = new QLineEdit(frame);
        StartInput->setObjectName("StartInput");
        StartInput->setGeometry(QRect(70, 80, 311, 51));
        StartInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        ArriveInput = new QLineEdit(frame);
        ArriveInput->setObjectName("ArriveInput");
        ArriveInput->setGeometry(QRect(70, 170, 311, 51));
        ArriveInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        ListButton = new QPushButton(frame);
        ListButton->setObjectName("ListButton");
        ListButton->setGeometry(QRect(170, 269, 100, 32));
        ListButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"    background-color: #535366; \n"
"    color: white; \n"
"    border-radius: 5px; \n"
"    }\n"
" QPushButton:hover { \n"
"    background-color: #555; \n"
"    }\n"
"  QPushButton:pressed { \n"
"    background-color: #777; \n"
"    }"));
        PassengerWindow->setCentralWidget(centralwidget);

        retranslateUi(PassengerWindow);

        QMetaObject::connectSlotsByName(PassengerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PassengerWindow)
    {
        PassengerWindow->setWindowTitle(QCoreApplication::translate("PassengerWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("PassengerWindow", "\354\266\234\353\260\234\354\247\200", nullptr));
        label_4->setText(QCoreApplication::translate("PassengerWindow", "\353\217\204\354\260\251\354\247\200", nullptr));
        StartInput->setPlaceholderText(QCoreApplication::translate("PassengerWindow", "\354\266\234\353\260\234\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        ArriveInput->setPlaceholderText(QCoreApplication::translate("PassengerWindow", "\354\266\234\353\260\234\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        ListButton->setText(QCoreApplication::translate("PassengerWindow", "\354\261\204\355\214\205\353\260\251 \353\252\251\353\241\235\353\263\264\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassengerWindow: public Ui_PassengerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERWINDOW_H
