/********************************************************************************
** Form generated from reading UI file 'chatroomwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOMWINDOW_H
#define UI_CHATROOMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QFrame *frame_2;
    QPushButton *SendButton;
    QTextEdit *MessageInput;
    QTextBrowser *messageBrowser;
    QPushButton *BackButton;
    QLabel *roomNameLabel;
    QLineEdit *nameLineEdit;
    QPushButton *NameButton;
    QPushButton *SendFileButton;
    QPushButton *EmoticonButton;

    void setupUi(QMainWindow *ChatRoomWindow)
    {
        if (ChatRoomWindow->objectName().isEmpty())
            ChatRoomWindow->setObjectName("ChatRoomWindow");
        ChatRoomWindow->resize(684, 557);
        centralwidget = new QWidget(ChatRoomWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;\n"
"border: 0px solid #535366;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(50, 410, 561, 71));
        frame_2->setStyleSheet(QString::fromUtf8("Background: #FFFFFF;\n"
"border: 1.5px solid #535366;\n"
"border-radius: 2px; "));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        SendButton = new QPushButton(frame_2);
        SendButton->setObjectName("SendButton");
        SendButton->setGeometry(QRect(480, 20, 61, 32));
        SendButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        MessageInput = new QTextEdit(frame_2);
        MessageInput->setObjectName("MessageInput");
        MessageInput->setGeometry(QRect(10, 10, 441, 51));
        MessageInput->setStyleSheet(QString::fromUtf8("Background: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"border: 0px solid #535366;"));
        messageBrowser = new QTextBrowser(frame);
        messageBrowser->setObjectName("messageBrowser");
        messageBrowser->setGeometry(QRect(50, 50, 561, 311));
        messageBrowser->setStyleSheet(QString::fromUtf8("Background: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"border: 1.5px solid #535366;"));
        BackButton = new QPushButton(frame);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(300, 490, 71, 32));
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
        roomNameLabel = new QLabel(frame);
        roomNameLabel->setObjectName("roomNameLabel");
        roomNameLabel->setGeometry(QRect(50, 20, 81, 16));
        roomNameLabel->setStyleSheet(QString::fromUtf8("color: rgb(83, 83, 102);\n"
"font-size: 15px;\n"
"font-weight: bold;"));
        nameLineEdit = new QLineEdit(frame);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(320, 10, 171, 31));
        nameLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; \n"
""));
        NameButton = new QPushButton(frame);
        NameButton->setObjectName("NameButton");
        NameButton->setGeometry(QRect(510, 10, 100, 32));
        NameButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        SendFileButton = new QPushButton(frame);
        SendFileButton->setObjectName("SendFileButton");
        SendFileButton->setGeometry(QRect(529, 370, 81, 32));
        SendFileButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
        EmoticonButton = new QPushButton(frame);
        EmoticonButton->setObjectName("EmoticonButton");
        EmoticonButton->setGeometry(QRect(430, 370, 81, 32));
        EmoticonButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        ChatRoomWindow->setCentralWidget(centralwidget);

        retranslateUi(ChatRoomWindow);

        QMetaObject::connectSlotsByName(ChatRoomWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatRoomWindow)
    {
        ChatRoomWindow->setWindowTitle(QCoreApplication::translate("ChatRoomWindow", "MainWindow", nullptr));
        SendButton->setText(QCoreApplication::translate("ChatRoomWindow", "\354\240\204\354\206\241", nullptr));
        BackButton->setText(QCoreApplication::translate("ChatRoomWindow", "\353\202\230\352\260\200\352\270\260", nullptr));
        roomNameLabel->setText(QCoreApplication::translate("ChatRoomWindow", "\354\261\204\355\214\205\353\260\251\354\235\264\353\246\204", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("ChatRoomWindow", "\353\213\211\353\204\244\354\236\204", nullptr));
        NameButton->setText(QCoreApplication::translate("ChatRoomWindow", "\353\213\211\353\204\244\354\236\204 \353\247\214\353\223\244\352\270\260", nullptr));
        SendFileButton->setText(QCoreApplication::translate("ChatRoomWindow", "\355\214\214\354\235\274\354\262\250\353\266\200", nullptr));
        EmoticonButton->setText(QCoreApplication::translate("ChatRoomWindow", "\354\235\264\353\252\250\355\213\260\354\275\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomWindow: public Ui_ChatRoomWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMWINDOW_H
