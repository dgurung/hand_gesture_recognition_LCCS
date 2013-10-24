#include "controller.h"

#include <QThread>

bool Controller::putCaptureInThread()
{
    //QThread* capturethread = new QThread;
    capture = new Capture;
    capture->connectToCamera();
    //capture->moveToThread(capturethread);
    // Setup the link
    // connect(capturethread, SIGNAL(started()), capture, SLOT(connectToCamera()));
    //connect(capture, SIGNAL(newOriginalFrame(QImage)), capturethread, SLOT(quit()));
    //capturethread->start();
    qDebug() << "Put in connection to camera -- controller";

    return true;
}
