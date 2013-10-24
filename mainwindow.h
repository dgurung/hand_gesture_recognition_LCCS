#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTest/QTestEventList>

#include "ui_mainwindow.h"

#include "Process_interface/controller.h"
#include "Process_interface/processing.h"
#include "Process_interface/imageprocessingdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void connetAndSetUpAllProcess();
    void signalSlotsInit();

private:
  //  Controller *controller;
    Capture *capture;
    Processing *process_image;
    int deviceNumber;
    QTimer *timer;

    ImageProcessingDialog *imageProcessingDialog;

public slots:
    void updateOriginalFrame(const QImage &qOriginalFrame);
    void updateProcessedFrame(const QImage &frame);
    void updateProcessIntermediateFrame(const QImage &frame);
    void setImageProcessingSettings();

private:
    // Opencv Processing elements
public:
    QTestEventList *eventos;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
