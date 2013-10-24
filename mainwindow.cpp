#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Process_interface/imageprocessingdialog.h"

#include<QtCore>


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    // Setup user interface
    ui->setupUi(this);

    // Connect menu dialogs
    imageProcessingDialog = new ImageProcessingDialog(this);

    // Connect Menu signals to slots
    signalSlotsInit();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connetAndSetUpAllProcess()
{
    // capture
    capture = new Capture(this);

    // Open camera
    capture->openCamera();

    // Process
    process_image = new Processing(this);

    // Setup or load cascade classifier
    process_image->setClassifier( "./xml/haarcascade_frontalface_alt2.xml" );
    process_image->setHandClassifier("./xml/hand.xml");
    process_image->setHandPalmClassifier("./xml/palm.xml");

    // connect original frame with update function
    connect(capture, SIGNAL(newOriginalFrame(QImage)), this,SLOT(updateOriginalFrame(QImage)));

    //connect original frame with processing unit
    connect(capture, SIGNAL(newOriginalFrameForProcessing(cv::Mat &)), process_image, SLOT(updateOriginalFrameForProcessing(cv::Mat &)));

    //connect processed image signal
    connect(process_image, SIGNAL(newProcessedFrame(QImage)), this, SLOT(updateProcessedFrame(QImage)));

    //connect  intermediate processed image signal
    connect(process_image, SIGNAL(newProcessIntermediateFrame(QImage)), this, SLOT(updateProcessIntermediateFrame(QImage)));


    // connect signals from Image Processing Dialog Setting's Flags with processor
    //connect(imageProcessingDialog, SIGNAL(newImageProcessingSettings(DetectorSettingFlags)), process, SLOT(updateImageProcessingFlags(DetectorSettingFlags)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), capture, SLOT(connectToCamera()));
    timer->start(50);        // least update period // but has less priority


//    eventos->addMouseClick(Qt::RightButton,0,QPoint(int(20),int(20)), -1);
//    eventos->simulate(this);

}

void MainWindow::updateOriginalFrame(const QImage &qOriginalFrame)
{
    ui->lblOriginal->setPixmap(QPixmap::fromImage(qOriginalFrame));
}

void MainWindow::updateProcessedFrame(const QImage &frame)
{
    ui->lblProcessed->setPixmap(QPixmap::fromImage(frame));
}

void MainWindow::updateProcessIntermediateFrame(const QImage &frame)
{
    //ui->lblIntermediate->setPixmap(QPixmap::fromImage(frame));
    ui->labl_mask->setPixmap(QPixmap::fromImage(frame));
}

void MainWindow::signalSlotsInit()
{
    // connect actions of all menu bar here
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionCamera_0, SIGNAL(triggered()), this, SLOT(connetAndSetUpAllProcess()));

    // connect image processing menu bar to dialog.
    connect(ui->actionImageProcessingSettings, SIGNAL(triggered()), this, SLOT(setImageProcessingSettings()));

} // signalSlotsInit()


void MainWindow::setImageProcessingSettings()
{
    // Prompt user:
    // If user presses OK button on dialog, update image processing settings
    imageProcessingDialog->setModal(false);
    imageProcessingDialog->exec();
}
