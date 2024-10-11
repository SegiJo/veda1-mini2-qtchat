/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *Logo;
    QLineEdit *NameInput;
    QLineEdit *PasswdInput;
    QPushButton *RegisterButton;
    QPushButton *BackButton;

    void setupUi(QMainWindow *SignupWindow)
    {
        if (SignupWindow->objectName().isEmpty())
            SignupWindow->setObjectName("SignupWindow");
        SignupWindow->resize(554, 402);
        centralwidget = new QWidget(SignupWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 30, 451, 341));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Logo = new QLabel(frame);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(160, 0, 131, 111));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/image/logo.png")));
        Logo->setScaledContents(true);
        NameInput = new QLineEdit(frame);
        NameInput->setObjectName("NameInput");
        NameInput->setGeometry(QRect(70, 120, 311, 51));
        NameInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        PasswdInput = new QLineEdit(frame);
        PasswdInput->setObjectName("PasswdInput");
        PasswdInput->setGeometry(QRect(70, 180, 311, 51));
        PasswdInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        RegisterButton = new QPushButton(frame);
        RegisterButton->setObjectName("RegisterButton");
        RegisterButton->setGeometry(QRect(270, 270, 100, 32));
        RegisterButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        BackButton->setGeometry(QRect(70, 270, 100, 32));
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
        SignupWindow->setCentralWidget(centralwidget);

        retranslateUi(SignupWindow);

        QMetaObject::connectSlotsByName(SignupWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignupWindow)
    {
        SignupWindow->setWindowTitle(QCoreApplication::translate("SignupWindow", "MainWindow", nullptr));
        Logo->setText(QString());
        NameInput->setPlaceholderText(QCoreApplication::translate("SignupWindow", "\354\235\264\353\246\204\354\235\204\354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        PasswdInput->setPlaceholderText(QCoreApplication::translate("SignupWindow", "\353\271\204\353\260\200\353\262\210\355\230\270\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.", nullptr));
        RegisterButton->setText(QCoreApplication::translate("SignupWindow", "\352\260\200\354\236\205\355\225\230\352\270\260", nullptr));
        BackButton->setText(QCoreApplication::translate("SignupWindow", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupWindow: public Ui_SignupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
