/********************************************************************************
** Form generated from reading UI file 'imageprocessingdialog.ui'
**
** Created: Fri Oct 11 16:01:21 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESSINGDIALOG_H
#define UI_IMAGEPROCESSINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProcessingDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *detectorTab;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *surfDetectorButton;
    QRadioButton *siftDetectorButton;
    QRadioButton *harrisDetectorButton;
    QRadioButton *fastDetectorButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *descriptorTab;
    QWidget *matcherTab;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImageProcessingDialog)
    {
        if (ImageProcessingDialog->objectName().isEmpty())
            ImageProcessingDialog->setObjectName(QString::fromUtf8("ImageProcessingDialog"));
        ImageProcessingDialog->resize(365, 251);
        verticalLayout_3 = new QVBoxLayout(ImageProcessingDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(ImageProcessingDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        detectorTab = new QWidget();
        detectorTab->setObjectName(QString::fromUtf8("detectorTab"));
        verticalLayout_2 = new QVBoxLayout(detectorTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        surfDetectorButton = new QRadioButton(detectorTab);
        surfDetectorButton->setObjectName(QString::fromUtf8("surfDetectorButton"));

        verticalLayout_2->addWidget(surfDetectorButton);

        siftDetectorButton = new QRadioButton(detectorTab);
        siftDetectorButton->setObjectName(QString::fromUtf8("siftDetectorButton"));

        verticalLayout_2->addWidget(siftDetectorButton);

        harrisDetectorButton = new QRadioButton(detectorTab);
        harrisDetectorButton->setObjectName(QString::fromUtf8("harrisDetectorButton"));

        verticalLayout_2->addWidget(harrisDetectorButton);

        fastDetectorButton = new QRadioButton(detectorTab);
        fastDetectorButton->setObjectName(QString::fromUtf8("fastDetectorButton"));

        verticalLayout_2->addWidget(fastDetectorButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(detectorTab, QString());
        descriptorTab = new QWidget();
        descriptorTab->setObjectName(QString::fromUtf8("descriptorTab"));
        tabWidget->addTab(descriptorTab, QString());
        matcherTab = new QWidget();
        matcherTab->setObjectName(QString::fromUtf8("matcherTab"));
        tabWidget->addTab(matcherTab, QString());

        verticalLayout->addWidget(tabWidget);

        line = new QFrame(ImageProcessingDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(ImageProcessingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(ImageProcessingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImageProcessingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImageProcessingDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ImageProcessingDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageProcessingDialog)
    {
        ImageProcessingDialog->setWindowTitle(QApplication::translate("ImageProcessingDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        surfDetectorButton->setText(QApplication::translate("ImageProcessingDialog", "SURF", 0, QApplication::UnicodeUTF8));
        siftDetectorButton->setText(QApplication::translate("ImageProcessingDialog", "SIFT", 0, QApplication::UnicodeUTF8));
        harrisDetectorButton->setText(QApplication::translate("ImageProcessingDialog", "Harris Corner", 0, QApplication::UnicodeUTF8));
        fastDetectorButton->setText(QApplication::translate("ImageProcessingDialog", "FAST", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(detectorTab), QApplication::translate("ImageProcessingDialog", "Detector", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(descriptorTab), QApplication::translate("ImageProcessingDialog", "Descriptor", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(matcherTab), QApplication::translate("ImageProcessingDialog", "Matcher", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageProcessingDialog: public Ui_ImageProcessingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESSINGDIALOG_H
