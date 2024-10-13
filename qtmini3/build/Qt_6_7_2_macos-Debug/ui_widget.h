/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *CloseButton;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QLineEdit *portLineEdit;
    QLineEdit *ipLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *adminLineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *passwordLineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->setEnabled(true);
        Widget->resize(400, 300);
        Widget->setMinimumSize(QSize(400, 300));
        Widget->setMaximumSize(QSize(400, 300));
        Widget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#535366;\n"
"color:#ffffff;\n"
"font-size: 20px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:44px;\n"
"width: 100%;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
"}\n"
"QFrame{\n"
"margin:2px;\n"
"border: 1px solid #dcdee0;;\n"
"border-radius: 24px;\n"
"background-color:rgb(255, 255, 255);\n"
"padding:10px;\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid rgb(41, 57, 85);\n"
"border-radius: 3px;\n"
"border-color:#dcdee0;\n"
"height:36px;\n"
"background: white;\n"
"padding-left: 12px;\n"
"padding-right: 12px;\n"
"border-color:#e4e5eb;\n"
"}\n"
"QLineEdit:hover {\n"
"border-color: #db9a45;\n"
"}"));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(Widget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        startButton = new QPushButton(frame);
        startButton->setObjectName("startButton");
        startButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"background-color: #535366;\n"
"\n"
"color: white;\n"
"\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #555;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #777;\n"
"\n"
"}"));

        horizontalLayout->addWidget(startButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName("CloseButton");
        CloseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"background-color: #535366;\n"
"\n"
"color: white;\n"
"\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #555;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"\n"
"background-color: #777;\n"
"\n"
"}"));

        horizontalLayout->addWidget(CloseButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        portLineEdit = new QLineEdit(frame);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));

        gridLayout->addWidget(portLineEdit, 1, 1, 1, 1);

        ipLineEdit = new QLineEdit(frame);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));

        gridLayout->addWidget(ipLineEdit, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        adminLineEdit = new QLineEdit(frame);
        adminLineEdit->setObjectName("adminLineEdit");
        adminLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));

        gridLayout->addWidget(adminLineEdit, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        passwordLineEdit = new QLineEdit(frame);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);

        QWidget::setTabOrder(ipLineEdit, portLineEdit);
        QWidget::setTabOrder(portLineEdit, adminLineEdit);
        QWidget::setTabOrder(adminLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, startButton);
        QWidget::setTabOrder(startButton, CloseButton);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\354\204\234\353\262\204 \353\241\234\352\267\270\354\235\270", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "\354\203\235\354\204\261", nullptr));
        CloseButton->setText(QCoreApplication::translate("Widget", "\353\213\253\352\270\260", nullptr));
        portLineEdit->setText(QCoreApplication::translate("Widget", "8077", nullptr));
        portLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        ipLineEdit->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        ipLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "IP \354\243\274\354\206\214", nullptr));
        adminLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\352\264\200\353\246\254\354\236\220 \352\263\204\354\240\225", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
