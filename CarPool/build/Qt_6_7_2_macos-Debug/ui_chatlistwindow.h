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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QLineEdit *ChatNameInput;
    QPushButton *FindChatButton;
    QPushButton *JoinChatButton;
    QPushButton *NewChatButton;
    QPushButton *BackButton;
    QTableView *JoinChatListtableView;

    void setupUi(QMainWindow *ChatListWindow)
    {
        if (ChatListWindow->objectName().isEmpty())
            ChatListWindow->setObjectName("ChatListWindow");
        ChatListWindow->resize(738, 523);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatListWindow->sizePolicy().hasHeightForWidth());
        ChatListWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(ChatListWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setEnabled(true);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ChatNameInput = new QLineEdit(frame);
        ChatNameInput->setObjectName("ChatNameInput");
        ChatNameInput->setGeometry(QRect(20, 20, 401, 31));
        ChatNameInput->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));
        FindChatButton = new QPushButton(frame);
        FindChatButton->setObjectName("FindChatButton");
        FindChatButton->setGeometry(QRect(450, 20, 60, 32));
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
        JoinChatButton->setGeometry(QRect(530, 20, 60, 32));
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
        NewChatButton->setGeometry(QRect(610, 20, 60, 32));
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
        BackButton = new QPushButton(frame);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(580, 450, 100, 32));
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
        JoinChatListtableView = new QTableView(frame);
        JoinChatListtableView->setObjectName("JoinChatListtableView");
        JoinChatListtableView->setGeometry(QRect(20, 60, 661, 381));
        JoinChatListtableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: rgb(255, 255, 255);  /* \355\205\214\354\235\264\353\270\224 \354\205\200 \353\260\260\352\262\275\354\203\211 */\n"
"    color: rgb(28, 28, 28);                /* \355\205\214\354\235\264\353\270\224 \354\205\200 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"    border: 1.5px solid #535366;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #D3D3D3;  /* \354\204\240\355\203\235\353\220\234 \354\205\200\354\235\230 \353\260\260\352\262\275\354\203\211 */\n"
"    color: black;               /* \354\204\240\355\203\235\353\220\234 \354\205\200\354\235\230 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    border: 1px solid #535366;  /* \354\205\200 \352\260\204 \355\205\214\353\221\220\353\246\254 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #535366;  /* \355\227\244\353\215\224 \353\260\260\352\262\275\354\203\211 */\n"
"    col"
                        "or: white;               /* \355\227\244\353\215\224 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"    border: 1px solid #535366;  /* \355\227\244\353\215\224 \355\205\214\353\221\220\353\246\254 */\n"
"    font-weight: bold;          /* \355\227\244\353\215\224 \352\270\200\354\224\250 \352\265\265\352\262\214 */\n"
"}"));

        gridLayout->addWidget(frame, 0, 0, 1, 1);

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
