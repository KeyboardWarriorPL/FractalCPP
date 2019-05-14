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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QDoubleSpinBox *colorSpin;
    QDoubleSpinBox *zoomSpin;
    QLabel *label;
    QPushButton *savButton;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QPushButton *genButton;
    QLabel *label_3;
    QGraphicsView *graphicsView;
    QLabel *label_2;
    QSpinBox *iterSpin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QString::fromUtf8("Main"));
        Main->resize(800, 600);
        centralwidget = new QWidget(Main);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        colorSpin = new QDoubleSpinBox(centralwidget);
        colorSpin->setObjectName(QString::fromUtf8("colorSpin"));
        colorSpin->setDecimals(4);
        colorSpin->setMaximum(1);
        colorSpin->setSingleStep(0.1);
        colorSpin->setValue(0.5);

        gridLayout->addWidget(colorSpin, 5, 0, 1, 1);

        zoomSpin = new QDoubleSpinBox(centralwidget);
        zoomSpin->setObjectName(QString::fromUtf8("zoomSpin"));
        zoomSpin->setDecimals(4);
        zoomSpin->setMinimum(0.0001);
        zoomSpin->setMaximum(1000);

        gridLayout->addWidget(zoomSpin, 7, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        savButton = new QPushButton(centralwidget);
        savButton->setObjectName(QString::fromUtf8("savButton"));

        gridLayout->addWidget(savButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 9, 0, 1, 1);

        genButton = new QPushButton(centralwidget);
        genButton->setObjectName(QString::fromUtf8("genButton"));

        gridLayout->addWidget(genButton, 1, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 10, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        iterSpin = new QSpinBox(centralwidget);
        iterSpin->setObjectName(QString::fromUtf8("iterSpin"));
        iterSpin->setMinimum(1);
        iterSpin->setMaximum(1000000);
        iterSpin->setValue(1000);

        gridLayout->addWidget(iterSpin, 3, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 3);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

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
        label->setText(QApplication::translate("Main", "Color shift:", 0, QApplication::UnicodeUTF8));
        savButton->setText(QApplication::translate("Main", "Save", 0, QApplication::UnicodeUTF8));
        genButton->setText(QApplication::translate("Main", "Generate", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Main", "Zoom:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Main", "Iterations:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONT_H
