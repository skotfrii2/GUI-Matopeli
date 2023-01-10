/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *widthSpinBox;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *heightSpinBox;
    QSpinBox *seedSpinBox;
    QLabel *label_4;
    QSpinBox *speedSpinBox;
    QPushButton *startButton;
    QPushButton *resetButton;
    QLabel *gameOverOrWon;
    QMenuBar *menubar;
    QMenu *menuMatopeli;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphView = new QGraphicsView(centralwidget);
        graphView->setObjectName(QString::fromUtf8("graphView"));
        graphView->setGeometry(QRect(200, 200, 361, 201));
        graphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(200, 50, 161, 120));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widthSpinBox = new QSpinBox(gridLayoutWidget);
        widthSpinBox->setObjectName(QString::fromUtf8("widthSpinBox"));
        widthSpinBox->setMinimum(1);

        gridLayout->addWidget(widthSpinBox, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        heightSpinBox = new QSpinBox(gridLayoutWidget);
        heightSpinBox->setObjectName(QString::fromUtf8("heightSpinBox"));
        heightSpinBox->setMinimum(1);

        gridLayout->addWidget(heightSpinBox, 2, 1, 1, 1);

        seedSpinBox = new QSpinBox(gridLayoutWidget);
        seedSpinBox->setObjectName(QString::fromUtf8("seedSpinBox"));

        gridLayout->addWidget(seedSpinBox, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        speedSpinBox = new QSpinBox(gridLayoutWidget);
        speedSpinBox->setObjectName(QString::fromUtf8("speedSpinBox"));
        speedSpinBox->setMinimum(1);
        speedSpinBox->setMaximum(9);
        speedSpinBox->setValue(6);

        gridLayout->addWidget(speedSpinBox, 3, 1, 1, 1);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(480, 170, 80, 24));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(390, 170, 80, 24));
        gameOverOrWon = new QLabel(centralwidget);
        gameOverOrWon->setObjectName(QString::fromUtf8("gameOverOrWon"));
        gameOverOrWon->setGeometry(QRect(60, 220, 71, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMatopeli = new QMenu(menubar);
        menuMatopeli->setObjectName(QString::fromUtf8("menuMatopeli"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMatopeli->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter height:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter seed number:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter width:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter speed:", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        gameOverOrWon->setText(QString());
        menuMatopeli->setTitle(QCoreApplication::translate("MainWindow", "Matopeli", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
