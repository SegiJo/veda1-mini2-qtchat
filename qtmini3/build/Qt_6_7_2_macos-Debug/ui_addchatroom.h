/********************************************************************************
** Form generated from reading UI file 'addchatroom.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCHATROOM_H
#define UI_ADDCHATROOM_H

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

class Ui_AddChatRoom
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *endLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *startLineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *chatnameLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addchatButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *AddChatRoom)
    {
        if (AddChatRoom->objectName().isEmpty())
            AddChatRoom->setObjectName("AddChatRoom");
        AddChatRoom->resize(400, 300);
        AddChatRoom->setMinimumSize(QSize(400, 300));
        AddChatRoom->setMaximumSize(QSize(400, 300));
        AddChatRoom->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(AddChatRoom);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(AddChatRoom);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("Background: rgb(234, 230, 224);\n"
"\n"
"border-radius: 5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        endLineEdit = new QLineEdit(frame);
        endLineEdit->setObjectName("endLineEdit");
        endLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));

        gridLayout->addWidget(endLineEdit, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        startLineEdit = new QLineEdit(frame);
        startLineEdit->setObjectName("startLineEdit");
        startLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));

        gridLayout->addWidget(startLineEdit, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        chatnameLineEdit = new QLineEdit(frame);
        chatnameLineEdit->setObjectName("chatnameLineEdit");
        chatnameLineEdit->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"\n"
"color: rgb(28, 28, 28);\n"
"\n"
"border: 1.5px solid #535366;\n"
"\n"
"border-radius: 5px;"));

        gridLayout->addWidget(chatnameLineEdit, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        addchatButton = new QPushButton(frame);
        addchatButton->setObjectName("addchatButton");
        addchatButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(addchatButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        closeButton = new QPushButton(frame);
        closeButton->setObjectName("closeButton");
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout->addWidget(frame);

        QWidget::setTabOrder(chatnameLineEdit, startLineEdit);
        QWidget::setTabOrder(startLineEdit, endLineEdit);
        QWidget::setTabOrder(endLineEdit, addchatButton);
        QWidget::setTabOrder(addchatButton, closeButton);

        retranslateUi(AddChatRoom);

        QMetaObject::connectSlotsByName(AddChatRoom);
    } // setupUi

    void retranslateUi(QWidget *AddChatRoom)
    {
        AddChatRoom->setWindowTitle(QCoreApplication::translate("AddChatRoom", "\354\203\210 \354\261\204\355\214\205\353\260\251 \354\266\224\352\260\200", nullptr));
        endLineEdit->setPlaceholderText(QCoreApplication::translate("AddChatRoom", "\353\217\204\354\260\251\354\247\200", nullptr));
        startLineEdit->setText(QString());
        startLineEdit->setPlaceholderText(QCoreApplication::translate("AddChatRoom", "\354\266\234\353\260\234\354\247\200", nullptr));
        chatnameLineEdit->setText(QString());
        chatnameLineEdit->setPlaceholderText(QCoreApplication::translate("AddChatRoom", "\354\261\204\355\214\205\353\260\251 \354\235\264\353\246\204", nullptr));
        addchatButton->setText(QCoreApplication::translate("AddChatRoom", "\354\203\235\354\204\261", nullptr));
        closeButton->setText(QCoreApplication::translate("AddChatRoom", "\353\213\253\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddChatRoom: public Ui_AddChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCHATROOM_H
