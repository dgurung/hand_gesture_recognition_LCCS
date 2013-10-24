/***************************************************************************
                                    Structure.h
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/background_segm.hpp>

struct DetectorSettingFlags
{
    bool surfDetectorOn;
    bool siftDetectorOn;
    bool fastDetectorOn;
    bool harrisDetectorOn;
};

struct GesturePresenceFlags
{
    bool handPresent;
    bool handsPalmPresent;
    bool handopen;
};

enum gesture {fist=0, palm=1, openpalm=2 };
#endif // STRUCTURE_H
