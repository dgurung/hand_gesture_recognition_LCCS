/***************************************************************************
                                    capture.cpp
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#include "capture.h"
#include "configure.h"

#include <QtCore>
#include <QDebug>
#include <QImage>

Capture::Capture(QObject *parent) :
    QObject(parent)
{

}

bool Capture::openCamera()
{
     cap.open(DEFAULT_CAMERA_DEV_NO);

     // Check if camera is connected
     if(cap.isOpened() == false)
     {
         qDebug() << "Camera not successfully connected.";
         return false;
     }

}

bool Capture::connectToCamera()
{
    cap.read(grabbedFrame);

    if(grabbedFrame.empty() == true)
    {
        qDebug("NO frame Grabbed");
        return 0;
    }

    cv::resize(grabbedFrame, grabbedFrame, cv::Size(), 0.5,0.5);
    cv::cvtColor(grabbedFrame, GrabbedFrameForDisplay, CV_BGR2RGB);

    //QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
    QImage qOriginalFrame((uchar*)GrabbedFrameForDisplay.data, GrabbedFrameForDisplay.cols, GrabbedFrameForDisplay.rows, GrabbedFrameForDisplay.step, QImage::Format_RGB888);

    emit newOriginalFrameForProcessing(grabbedFrame);
    emit newOriginalFrame(qOriginalFrame);

    return true;

}
