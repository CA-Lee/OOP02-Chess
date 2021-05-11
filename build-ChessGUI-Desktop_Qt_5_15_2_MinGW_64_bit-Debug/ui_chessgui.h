/********************************************************************************
** Form generated from reading UI file 'chessgui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSGUI_H
#define UI_CHESSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessGUI
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ChessGUI)
    {
        if (ChessGUI->objectName().isEmpty())
            ChessGUI->setObjectName(QString::fromUtf8("ChessGUI"));
        ChessGUI->resize(1200, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChessGUI->sizePolicy().hasHeightForWidth());
        ChessGUI->setSizePolicy(sizePolicy);
        ChessGUI->setMinimumSize(QSize(1200, 720));
        ChessGUI->setMaximumSize(QSize(1200, 720));
        ChessGUI->setToolButtonStyle(Qt::ToolButtonTextOnly);
        centralwidget = new QWidget(ChessGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1200, 720));
        label->setMinimumSize(QSize(411, 241));
        label->setFrameShape(QFrame::NoFrame);
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/background.png")));
        label->setScaledContents(true);
        ChessGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChessGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        ChessGUI->setMenuBar(menubar);

        retranslateUi(ChessGUI);

        QMetaObject::connectSlotsByName(ChessGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ChessGUI)
    {
        ChessGUI->setWindowTitle(QCoreApplication::translate("ChessGUI", "Chess", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChessGUI: public Ui_ChessGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSGUI_H
