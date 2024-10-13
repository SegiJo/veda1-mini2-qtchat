/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *chatroom_tab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *chatlineEdit;
    QPushButton *searchButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *chatmanageButton;
    QTableView *chatTable;
    QWidget *user_tab;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *userlineEdit;
    QPushButton *usersearchButton;
    QPushButton *userdeleteButton;
    QTableView *userTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("/* \354\240\204\354\262\264 \355\203\255 \354\234\204\354\240\257 \353\260\260\352\262\275\354\203\211 */\n"
"QTabWidget::pane {\n"
"   Background: rgb(234, 230, 224);\n"
"    border: 1px solid #535366;   /* SLATE \354\203\211\354\203\201 */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* \355\203\255 \353\260\224 \354\212\244\355\203\200\354\235\274 \354\204\244\354\240\225 (\355\203\255 \353\262\204\355\212\274 \354\230\201\354\227\255) */\n"
"QTabBar::tab {\n"
"    background-color: #535366;   /* SLATE \354\203\211\354\203\201 */\n"
"    color: #FFFFFF;              /* WHITE \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"    padding: 5px;\n"
"    border: 1px solid #535366;   /* \355\205\214\353\221\220\353\246\254 SLATE */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"/* \354\204\240\355\203\235\353\220\234 \355\203\255 \354\212\244\355\203\200\354\235\274 */\n"
"QTabBar::tab:selected {\n"
"    background-color: #535366;   /* CHARCOAL \354\203\211"
                        "\354\203\201 */\n"
"    color: #FFFFFF;              /* WHITE \355\205\215\354\212\244\355\212\270 */\n"
"    font-weight: bold;           /* \354\204\240\355\203\235\353\220\234 \355\203\255 \352\265\265\354\235\200 \352\270\200\354\224\250 */\n"
"}\n"
"\n"
"/* \353\271\204\355\231\234\354\204\261 \355\203\255 \354\212\244\355\203\200\354\235\274 */\n"
"QTabBar::tab:!selected {\n"
"    background-color: #EAe6E0;   /* CANVAS \354\203\211\354\203\201 */\n"
"    color: #535366;              /* SLATE \355\205\215\354\212\244\355\212\270 */\n"
"}\n"
"\n"
"/* \355\203\255 \353\260\224\354\235\230 \352\260\204\352\262\251 \354\241\260\354\240\225 */\n"
"QTabBar::tab {\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"/* \355\203\255 \353\202\264\354\232\251\354\235\230 \353\260\260\352\262\275 \353\260\217 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"QTabWidget::pane > QWidget {\n"
"  Background: rgb(234, 230, 224);  /* WHITE \354\203\211\354\203\201 */\n"
"    color: #1C1C1C;              /* CHARCOA"
                        "L \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"}\n"
""));
        chatroom_tab = new QWidget();
        chatroom_tab->setObjectName("chatroom_tab");
        gridLayout_2 = new QGridLayout(chatroom_tab);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(4, 10, 4, 10);
        chatlineEdit = new QLineEdit(chatroom_tab);
        chatlineEdit->setObjectName("chatlineEdit");
        chatlineEdit->setMaximumSize(QSize(300, 300));
        chatlineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; "));

        horizontalLayout->addWidget(chatlineEdit);

        searchButton = new QPushButton(chatroom_tab);
        searchButton->setObjectName("searchButton");
        searchButton->setMaximumSize(QSize(16777215, 300));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        horizontalLayout->addWidget(searchButton);

        addButton = new QPushButton(chatroom_tab);
        addButton->setObjectName("addButton");
        addButton->setMaximumSize(QSize(16777215, 300));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(chatroom_tab);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setMaximumSize(QSize(16777215, 300));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        horizontalLayout->addWidget(deleteButton);

        chatmanageButton = new QPushButton(chatroom_tab);
        chatmanageButton->setObjectName("chatmanageButton");
        chatmanageButton->setMaximumSize(QSize(16777215, 300));
        chatmanageButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        horizontalLayout->addWidget(chatmanageButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        chatTable = new QTableView(chatroom_tab);
        chatTable->setObjectName("chatTable");
        chatTable->setStyleSheet(QString::fromUtf8(" QTableView {\n"
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
"    co"
                        "lor: white;               /* \355\227\244\353\215\224 \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201 */\n"
"    border: 1px solid #535366;  /* \355\227\244\353\215\224 \355\205\214\353\221\220\353\246\254 */\n"
"    font-weight: bold;          /* \355\227\244\353\215\224 \352\270\200\354\224\250 \352\265\265\352\262\214 */\n"
"}"));

        gridLayout_2->addWidget(chatTable, 1, 0, 1, 1);

        tabWidget->addTab(chatroom_tab, QString());
        user_tab = new QWidget();
        user_tab->setObjectName("user_tab");
        gridLayout_3 = new QGridLayout(user_tab);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(4, 10, 4, 10);
        userlineEdit = new QLineEdit(user_tab);
        userlineEdit->setObjectName("userlineEdit");
        userlineEdit->setMaximumSize(QSize(450, 300));
        userlineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: rgb(28, 28, 28);\n"
"border: 1.5px solid #535366;\n"
"border-radius: 5px; \n"
""));

        horizontalLayout_2->addWidget(userlineEdit);

        usersearchButton = new QPushButton(user_tab);
        usersearchButton->setObjectName("usersearchButton");
        usersearchButton->setMaximumSize(QSize(16777215, 300));
        usersearchButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        horizontalLayout_2->addWidget(usersearchButton);

        userdeleteButton = new QPushButton(user_tab);
        userdeleteButton->setObjectName("userdeleteButton");
        userdeleteButton->setMaximumSize(QSize(16777215, 300));
        userdeleteButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

        horizontalLayout_2->addWidget(userdeleteButton);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 2, 1);

        userTable = new QTableView(user_tab);
        userTable->setObjectName("userTable");
        userTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
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

        gridLayout_3->addWidget(userTable, 2, 0, 1, 1);

        tabWidget->addTab(user_tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\353\251\224\354\235\270 \355\231\224\353\251\264", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\352\262\200\354\203\211", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\354\203\210 \354\261\204\355\214\205\353\260\251 \354\266\224\352\260\200", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\354\204\240\355\203\235\355\225\234 \354\261\204\355\214\205\353\260\251 \354\202\255\354\240\234", nullptr));
        chatmanageButton->setText(QCoreApplication::translate("MainWindow", "\354\261\204\355\214\205\353\260\251 \353\251\224\354\204\270\354\247\200 \352\264\200\353\246\254", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(chatroom_tab), QCoreApplication::translate("MainWindow", "\354\261\204\355\214\205\353\260\251 \352\264\200\353\246\254", nullptr));
        usersearchButton->setText(QCoreApplication::translate("MainWindow", "\352\262\200\354\203\211", nullptr));
        userdeleteButton->setText(QCoreApplication::translate("MainWindow", "\354\204\240\355\203\235\355\225\234 \354\202\254\354\232\251\354\236\220 \354\202\255\354\240\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(user_tab), QCoreApplication::translate("MainWindow", "\354\202\254\354\232\251\354\236\220 \352\264\200\353\246\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
