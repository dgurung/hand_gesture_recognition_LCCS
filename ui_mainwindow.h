/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Oct 11 16:01:21 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCamera_0;
    QAction *actionExit;
    QAction *actionImageProcessingSettings;
    QWidget *centralWidget;
    QLabel *lblOriginal;
    QLabel *lblProcessed;
    QLabel *label;
    QLabel *label_2;
    QLabel *labl_mask;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *imageProcessingMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(685, 589);
        actionCamera_0 = new QAction(MainWindow);
        actionCamera_0->setObjectName(QString::fromUtf8("actionCamera_0"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setCheckable(true);
        actionImageProcessingSettings = new QAction(MainWindow);
        actionImageProcessingSettings->setObjectName(QString::fromUtf8("actionImageProcessingSettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lblOriginal = new QLabel(centralWidget);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setGeometry(QRect(16, 36, 320, 240));
        lblOriginal->setAutoFillBackground(true);
        lblProcessed = new QLabel(centralWidget);
        lblProcessed->setObjectName(QString::fromUtf8("lblProcessed"));
        lblProcessed->setGeometry(QRect(352, 36, 320, 240));
        lblProcessed->setAutoFillBackground(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(464, 4, 113, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(128, 8, 101, 17));
        labl_mask = new QLabel(centralWidget);
        labl_mask->setObjectName(QString::fromUtf8("labl_mask"));
        labl_mask->setGeometry(QRect(184, 304, 309, 209));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 685, 24));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        imageProcessingMenu = new QMenu(menuBar);
        imageProcessingMenu->setObjectName(QString::fromUtf8("imageProcessingMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(imageProcessingMenu->menuAction());
        menuMenu->addAction(actionCamera_0);
        menuMenu->addAction(actionExit);
        imageProcessingMenu->addAction(actionImageProcessingSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCamera_0->setText(QApplication::translate("MainWindow", "Camera 0", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionImageProcessingSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        lblOriginal->setText(QString());
        lblProcessed->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Output Window", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Input Video", 0, QApplication::UnicodeUTF8));
        labl_mask->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        imageProcessingMenu->setTitle(QApplication::translate("MainWindow", "Image Processing", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
