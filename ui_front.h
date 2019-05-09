/********************************************************************************
** Form generated from reading UI file 'front.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRONT_H
#define UI_FRONT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QPushButton *savButton;
    QPushButton *genButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QString::fromUtf8("Main"));
        Main->resize(800, 600);
        centralwidget = new QWidget(Main);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(6, 9, 781, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        graphicsView = new QGraphicsView(gridLayoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 2, 4, 2);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 3, 0, 1, 1);

        savButton = new QPushButton(gridLayoutWidget);
        savButton->setObjectName(QString::fromUtf8("savButton"));

        gridLayout->addWidget(savButton, 1, 0, 1, 1);

        genButton = new QPushButton(gridLayoutWidget);
        genButton->setObjectName(QString::fromUtf8("genButton"));

        gridLayout->addWidget(genButton, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(2, 4);
        Main->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Main->setMenuBar(menubar);
        statusbar = new QStatusBar(Main);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Main->setStatusBar(statusbar);

        retranslateUi(Main);

        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "Fractal Gen", 0, QApplication::UnicodeUTF8));
        savButton->setText(QApplication::translate("Main", "Save", 0, QApplication::UnicodeUTF8));
        genButton->setText(QApplication::translate("Main", "Generate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONT_H
