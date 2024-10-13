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
        chatroom_tab = new QWidget();
        chatroom_tab->setObjectName("chatroom_tab");
        gridLayout_2 = new QGridLayout(chatroom_tab);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        chatlineEdit = new QLineEdit(chatroom_tab);
        chatlineEdit->setObjectName("chatlineEdit");

        horizontalLayout->addWidget(chatlineEdit);

        searchButton = new QPushButton(chatroom_tab);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);

        addButton = new QPushButton(chatroom_tab);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(chatroom_tab);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        chatmanageButton = new QPushButton(chatroom_tab);
        chatmanageButton->setObjectName("chatmanageButton");

        horizontalLayout->addWidget(chatmanageButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        chatTable = new QTableView(chatroom_tab);
        chatTable->setObjectName("chatTable");

        gridLayout_2->addWidget(chatTable, 1, 0, 1, 1);

        tabWidget->addTab(chatroom_tab, QString());
        user_tab = new QWidget();
        user_tab->setObjectName("user_tab");
        gridLayout_3 = new QGridLayout(user_tab);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        userlineEdit = new QLineEdit(user_tab);
        userlineEdit->setObjectName("userlineEdit");

        horizontalLayout_2->addWidget(userlineEdit);

        usersearchButton = new QPushButton(user_tab);
        usersearchButton->setObjectName("usersearchButton");

        horizontalLayout_2->addWidget(usersearchButton);

        userdeleteButton = new QPushButton(user_tab);
        userdeleteButton->setObjectName("userdeleteButton");

        horizontalLayout_2->addWidget(userdeleteButton);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 2, 1);

        userTable = new QTableView(user_tab);
        userTable->setObjectName("userTable");

        gridLayout_3->addWidget(userTable, 2, 0, 1, 1);

        tabWidget->addTab(user_tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
