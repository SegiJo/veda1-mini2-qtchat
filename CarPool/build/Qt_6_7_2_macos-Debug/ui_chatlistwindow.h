/********************************************************************************
** Form generated from reading UI file 'chatlistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLISTWINDOW_H
#define UI_CHATLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *ChatNameInput;
    QPushButton *FindChatButton;
    QPushButton *JoinChatButton;
    QPushButton *NewChatButton;
    QListWidget *JoinChatListWidget;
    QPushButton *BackButton;

    void setupUi(QMainWindow *ChatListWindow)
    {
        if (ChatListWindow->objectName().isEmpty())
            ChatListWindow->setObjectName("ChatListWindow");
        ChatListWindow->resize(715, 490);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatListWindow->sizePolicy().hasHeightForWidth());
        ChatListWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(ChatListWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 10, 601, 461));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ChatNameInput = new QLineEdit(frame);
        ChatNameInput->setObjectName("ChatNameInput");
        ChatNameInput->setGeometry(QRect(20, 20, 341, 31));
        ChatNameInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        FindChatButton = new QPushButton(frame);
        FindChatButton->setObjectName("FindChatButton");
        FindChatButton->setGeometry(QRect(370, 20, 60, 32));
        FindChatButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        JoinChatButton = new QPushButton(frame);
        JoinChatButton->setObjectName("JoinChatButton");
        JoinChatButton->setGeometry(QRect(450, 20, 60, 32));
        JoinChatButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        NewChatButton = new QPushButton(frame);
        NewChatButton->setObjectName("NewChatButton");
        NewChatButton->setGeometry(QRect(520, 20, 60, 32));
        NewChatButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        JoinChatListWidget = new QListWidget(frame);
        JoinChatListWidget->setObjectName("JoinChatListWidget");
        JoinChatListWidget->setGeometry(QRect(20, 60, 561, 341));
        JoinChatListWidget->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        BackButton = new QPushButton(frame);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(480, 410, 100, 32));
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
        ChatListWindow->setCentralWidget(centralwidget);

        retranslateUi(ChatListWindow);

        QMetaObject::connectSlotsByName(ChatListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatListWindow)
    {
        ChatListWindow->setWindowTitle(QCoreApplication::translate("ChatListWindow", "MainWindow", nullptr));
        FindChatButton->setText(QCoreApplication::translate("ChatListWindow", "\352\262\200\354\203\211", nullptr));
        JoinChatButton->setText(QCoreApplication::translate("ChatListWindow", "\354\260\270\352\260\200", nullptr));
        NewChatButton->setText(QCoreApplication::translate("ChatListWindow", "\354\203\235\354\204\261", nullptr));
        BackButton->setText(QCoreApplication::translate("ChatListWindow", "\353\202\230\352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListWindow: public Ui_ChatListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLISTWINDOW_H
