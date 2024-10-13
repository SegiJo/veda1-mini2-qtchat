/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *NameInput;
    QLineEdit *PasswdInput;
    QPushButton *LoginButton;
    ClickableLabel *RegisterButton;
    QLineEdit *IpInput;
    QLineEdit *PortInput;
    QPushButton *CloseButton;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(554, 402);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 10, 450, 380));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        NameInput = new QLineEdit(frame);
        NameInput->setObjectName("NameInput");
        NameInput->setGeometry(QRect(70, 170, 311, 51));
        NameInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        PasswdInput = new QLineEdit(frame);
        PasswdInput->setObjectName("PasswdInput");
        PasswdInput->setGeometry(QRect(70, 230, 311, 51));
        PasswdInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        PasswdInput->setEchoMode(QLineEdit::Password);
        LoginButton = new QPushButton(frame);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(270, 330, 100, 32));
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        RegisterButton = new ClickableLabel(frame);
        RegisterButton->setObjectName("RegisterButton");
        RegisterButton->setGeometry(QRect(70, 290, 58, 16));
        RegisterButton->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #535366; /* \355\214\214\353\236\200\354\203\211 \355\205\215\354\212\244\355\212\270 */\n"
"    font-weight: bold;\n"
"    text-decoration: underline; /* \353\260\221\354\244\204 \354\266\224\352\260\200 */\n"
"}\n"
"QLabel:hover {\n"
"    color: #4682B4; /* \353\247\210\354\232\260\354\212\244\353\245\274 \354\230\254\353\240\270\354\235\204 \353\225\214 \354\203\211\354\203\201 \353\263\200\352\262\275 */\n"
"}"));
        IpInput = new QLineEdit(frame);
        IpInput->setObjectName("IpInput");
        IpInput->setGeometry(QRect(70, 50, 311, 51));
        IpInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        PortInput = new QLineEdit(frame);
        PortInput->setObjectName("PortInput");
        PortInput->setGeometry(QRect(70, 110, 311, 51));
        PortInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName("CloseButton");
        CloseButton->setGeometry(QRect(70, 330, 100, 32));
        CloseButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        NameInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\354\235\264\353\246\204\354\235\204 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        PasswdInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\353\271\204\353\260\200\353\262\210\355\230\270\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        LoginButton->setText(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
        RegisterButton->setText(QCoreApplication::translate("LoginWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        IpInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "IP\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        PortInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Port\353\262\210\355\230\270\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        CloseButton->setText(QCoreApplication::translate("LoginWindow", "\353\213\253\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
