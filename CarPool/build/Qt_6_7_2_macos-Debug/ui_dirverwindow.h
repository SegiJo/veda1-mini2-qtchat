/********************************************************************************
** Form generated from reading UI file 'dirverwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRVERWINDOW_H
#define UI_DIRVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DirverWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *pin;
    QLabel *label;
    QLabel *pin_2;
    QLabel *label_2;
    QLineEdit *StartInput;
    QLineEdit *ArriveInput;
    QPushButton *MakeButton;

    void setupUi(QMainWindow *DirverWindow)
    {
        if (DirverWindow->objectName().isEmpty())
            DirverWindow->setObjectName("DirverWindow");
        DirverWindow->resize(554, 402);
        centralwidget = new QWidget(DirverWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 30, 452, 341));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pin = new QLabel(frame);
        pin->setObjectName("pin");
        pin->setGeometry(QRect(60, 40, 40, 40));
        pin->setPixmap(QPixmap(QString::fromUtf8(":/image/pin.png")));
        pin->setScaledContents(true);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 55, 51, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        pin_2 = new QLabel(frame);
        pin_2->setObjectName("pin_2");
        pin_2->setGeometry(QRect(60, 130, 40, 40));
        pin_2->setPixmap(QPixmap(QString::fromUtf8(":/image/pin.png")));
        pin_2->setScaledContents(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 140, 51, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
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
        MakeButton = new QPushButton(frame);
        MakeButton->setObjectName("MakeButton");
        MakeButton->setGeometry(QRect(170, 260, 100, 32));
        MakeButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"    background-color: #535366; \n"
"    color: white; \n"
"    border-radius: 5px; \n"
"    }\n"
" QPushButton:hover { \n"
"    background-color: #555; \n"
"    }\n"
"  QPushButton:pressed { \n"
"    background-color: #777; \n"
"    }\n"
""));
        DirverWindow->setCentralWidget(centralwidget);

        retranslateUi(DirverWindow);

        QMetaObject::connectSlotsByName(DirverWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DirverWindow)
    {
        DirverWindow->setWindowTitle(QCoreApplication::translate("DirverWindow", "MainWindow", nullptr));
        pin->setText(QString());
        label->setText(QCoreApplication::translate("DirverWindow", "\354\266\234\353\260\234\354\247\200", nullptr));
        pin_2->setText(QString());
        label_2->setText(QCoreApplication::translate("DirverWindow", "\353\217\204\354\260\251\354\247\200", nullptr));
        StartInput->setPlaceholderText(QCoreApplication::translate("DirverWindow", "\354\266\234\353\260\234\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        ArriveInput->setPlaceholderText(QCoreApplication::translate("DirverWindow", "\353\217\204\354\260\251\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        MakeButton->setText(QCoreApplication::translate("DirverWindow", "\354\261\204\355\214\205\353\260\251 \353\247\214\353\223\244\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DirverWindow: public Ui_DirverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRVERWINDOW_H
