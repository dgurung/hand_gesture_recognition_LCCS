/***************************************************************************
                                    capture.h
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#ifndef CAPTURE_H
#define CAPTURE_H

#include <QObject>
#include <QDebug>
#include <QtCore>

// OpenCV header files
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// inherit QThread
class Capture : public QObject
{
    Q_OBJECT
public:
    explicit Capture(QObject *parent = 0);

private:
    cv::VideoCapture cap;
    cv::Mat grabbedFrame;
    cv::Mat GrabbedFrameForDisplay;
    QTimer timer;

public slots:
    bool connectToCamera();
    bool openCamera();

signals:
    void newOriginalFrame(const QImage &qOriginalFrame);
    void newOriginalFrameForProcessing(cv::Mat &);
};

#endif // CAPTURE_H
