/***************************************************************************
                                    processing.h
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include <QtGui>
#include <QtGui/QCursor> 


// OpenCV header files
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>
#include "opencv2/objdetect/objdetect.hpp"


#include "imageprocessingdialog.h"
#include "Structure.h"
#include "configure.h"
#include "usefulMathFunctions.h"
#include "tracking/tracking.h"

#include <vector>
#include <queue>

using namespace std;
using namespace cv;

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = 0);

private:
    cv::Mat currentFrame;
    cv::Mat currentFrameGrayscale;
    cv::Mat Processedframe;
    cv::Mat drawing;

    cv::Mat rgb[3];
    cv::Mat nrgb;
    cv::Mat hsv;
    cv::Mat gray;

    cv::BackgroundSubtractorMOG2 bg;
    cv::Mat fg_msk;

    cv::Mat background;
    cv::Mat backImage;
    cv::Mat mask, mask_hsv, mask_nrgb, maskedProcessedframe; // objects for images
    cv::Mat mask_spm;

    cv::Mat frame_gray; // variable for face detection
    cv::Mat roi_face;

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    CascadeClassifier face_cascade;
    CascadeClassifier hand_cascade;
    CascadeClassifier hand_palm_cascade;
    std::vector<cv::Rect> faces;
    std::vector<cv::Rect> hands;
    std::vector<cv::Rect> handsPalm;

    // Find the convex hull object for each contour
    vector<vector<Point> > hull;
    vector<vector<int> > hullsI;
    vector<vector<Vec4i> > convdefect;

    // variable for histograms
    cv::MatND hist;
    cv::MatND backproj;

    // tracking point
    Point trackingpt;

    // tracked point
    cv::Point trackedpt;

    // Kalman Parameters
    tracking KFtrack;

    struct GesturePresenceFlags gestureFlag;
signals:
    void newProcessedFrame(const QImage &);
    void newProcessIntermediateFrame(const QImage &);

public slots:
    void updateOriginalFrameForProcessing(cv::Mat &);
    void updateImageProcessingFlags(struct DetectorSettingFlags d_SettingFlags);



    // processing functions

private:

    bool detectFace();
    bool detectHandFist();
    bool detectHandPalm();
    bool detectFingerAndCentroidInOpenPalm(Mat &frame);

    cv::Mat getNormalizedRGB(const cv::Mat& rgb);

    void spm_predict(const Mat& img_hsv, Mat& output_mask);

    cv::Scalar refineSegments(const Mat& img, const Mat& mask, Mat& dst, vector<Point>& contour, vector<Point>& second_contour, Point2i& previous);

    void subtractbackground(cv::Mat &frame);

    void takeBGImage();

    string GestureFromBuffer(struct GesturePresenceFlags gesture);
public:
    void setClassifier( String face_cascade_name)
    { face_cascade.load(face_cascade_name); }
    void setHandClassifier( String hand_cascade_name)
    { hand_cascade.load(hand_cascade_name);}
    void setHandPalmClassifier(String hand_palm_cascade_name)
    { hand_palm_cascade.load(hand_palm_cascade_name);}

private:
    //std::queue<int> frameGestureBufferIdx;
    std::vector<int> frameGestureBufferIdx;
};

#endif // PROCESSING_H
