#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>
#include <QtGui>


#include "Process_interface/capture.h"

class CaptureThread : public QThread
{
public:
    CaptureThread(int deviceNumber);
    void putinCaptureThread();

private:
    Capture *capture;

};

#endif // CAPTURETHREAD_H
