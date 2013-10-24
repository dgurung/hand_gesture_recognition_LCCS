#include "Process_interface/capturethread.h"

#include <QDebug>

CaptureThread::CaptureThread(int deviceNumber)
{
    dvNo = deviceNumber;
}

void CaptureThread::putinCaptureThread()
{
    QThread* thread = new QThread;
    capture = new Capture(dvNo);
    capture->moveToThread(thread);
    // Setup the link
    connect(thread, SIGNAL(started()), capture, SLOT(connectToCamera(int)));
    thread->start();
    qDebug() << "connection Put in thread";
}


