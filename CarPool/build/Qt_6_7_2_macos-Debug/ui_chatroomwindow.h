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
    QFrame *frame;
    QFrame *frame_2;
    QPushButton *SendButton;
    QTextEdit *MessageInput;
    QTextBrowser *textBrowser;
    QPushButton *BackButton;

    void setupUi(QMainWindow *ChatRoomWindow)
    {
        if (ChatRoomWindow->objectName().isEmpty())
            ChatRoomWindow->setObjectName("ChatRoomWindow");
        ChatRoomWindow->resize(715, 490);
        centralwidget = new QWidget(ChatRoomWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 10, 601, 461));
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;\n"
"border: 0px solid #535366;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 340, 541, 71));
        frame_2->setStyleSheet(QString::fromUtf8("Background: #FFFFFF;\n"
"border: 1.5px solid #535366;\n"
"border-radius: 0px; "));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        SendButton = new QPushButton(frame_2);
        SendButton->setObjectName("SendButton");
        SendButton->setGeometry(QRect(470, 20, 61, 32));
        SendButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"    background-color: #535366; \n"
"    color: white; \n"
"    border-radius: 5px; QPushButton { \n"
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
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 20, 541, 311));
        textBrowser->setStyleSheet(QString::fromUtf8("Background: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"border: 1.5px solid #535366;"));
        BackButton = new QPushButton(frame);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(30, 420, 61, 32));
        BackButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"    background-color: #535366; \n"
"    color: white; \n"
"    border-radius: 5px; QPushButton { \n"
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
"    }\n"
" QPushButton:hover { \n"
"    background-color: #555; \n"
"    }\n"
"  QPushButton:pressed { \n"
"    background-color: #777; \n"
"    }"));
        ChatRoomWindow->setCentralWidget(centralwidget);

        retranslateUi(ChatRoomWindow);

        QMetaObject::connectSlotsByName(ChatRoomWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatRoomWindow)
    {
        ChatRoomWindow->setWindowTitle(QCoreApplication::translate("ChatRoomWindow", "MainWindow", nullptr));
        SendButton->setText(QCoreApplication::translate("ChatRoomWindow", "\354\240\204\354\206\241", nullptr));
        BackButton->setText(QCoreApplication::translate("ChatRoomWindow", "\353\202\230\352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomWindow: public Ui_ChatRoomWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMWINDOW_H
