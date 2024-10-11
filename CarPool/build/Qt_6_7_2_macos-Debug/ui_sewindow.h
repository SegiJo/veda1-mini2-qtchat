/********************************************************************************
** Form generated from reading UI file 'sewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEWINDOW_H
#define UI_SEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SEWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLineEdit *StartInput;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *FinishInput;
    QLabel *label_4;
    QPushButton *NewButton;
    QPushButton *BackButton;
    QLineEdit *ChatNameInput;
    QLabel *label_5;

    void setupUi(QMainWindow *SEWindow)
    {
        if (SEWindow->objectName().isEmpty())
            SEWindow->setObjectName("SEWindow");
        SEWindow->resize(554, 429);
        centralwidget = new QWidget(SEWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 10, 451, 381));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 120, 40, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/pin.png")));
        label->setScaledContents(true);
        StartInput = new QLineEdit(frame);
        StartInput->setObjectName("StartInput");
        StartInput->setGeometry(QRect(70, 150, 311, 51));
        StartInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 130, 58, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 210, 40, 40));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/image/pin.png")));
        label_3->setScaledContents(true);
        FinishInput = new QLineEdit(frame);
        FinishInput->setObjectName("FinishInput");
        FinishInput->setGeometry(QRect(70, 240, 311, 51));
        FinishInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 220, 58, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        NewButton = new QPushButton(frame);
        NewButton->setObjectName("NewButton");
        NewButton->setGeometry(QRect(280, 320, 100, 32));
        NewButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        BackButton = new QPushButton(frame);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(70, 320, 100, 32));
        BackButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        ChatNameInput = new QLineEdit(frame);
        ChatNameInput->setObjectName("ChatNameInput");
        ChatNameInput->setGeometry(QRect(70, 60, 311, 51));
        ChatNameInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 40, 71, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        SEWindow->setCentralWidget(centralwidget);

        retranslateUi(SEWindow);

        QMetaObject::connectSlotsByName(SEWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SEWindow)
    {
        SEWindow->setWindowTitle(QCoreApplication::translate("SEWindow", "MainWindow", nullptr));
        label->setText(QString());
        StartInput->setPlaceholderText(QCoreApplication::translate("SEWindow", "\354\266\234\353\260\234\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        label_2->setText(QCoreApplication::translate("SEWindow", "\354\266\234\353\260\234\354\247\200", nullptr));
        label_3->setText(QString());
        FinishInput->setPlaceholderText(QCoreApplication::translate("SEWindow", "\353\217\204\354\260\251\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        label_4->setText(QCoreApplication::translate("SEWindow", "\353\217\204\354\260\251\354\247\200", nullptr));
        NewButton->setText(QCoreApplication::translate("SEWindow", "\354\203\235\354\204\261", nullptr));
        BackButton->setText(QCoreApplication::translate("SEWindow", "\353\222\244\353\241\234", nullptr));
        ChatNameInput->setPlaceholderText(QCoreApplication::translate("SEWindow", "\354\261\204\355\214\205\353\260\251\354\235\264\353\246\204\354\235\204 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        label_5->setText(QCoreApplication::translate("SEWindow", "\354\261\204\355\214\205\353\260\251\354\235\264\353\246\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SEWindow: public Ui_SEWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEWINDOW_H
