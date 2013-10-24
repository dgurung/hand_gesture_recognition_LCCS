

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QtCore>

// OpenCV header files
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "capture.h"

class Controller : public QObject
{
    Q_OBJECT
public slots:
    bool putCaptureInThread();
public:
    Capture *capture;
    
};

#endif // CONTROLLER_H
