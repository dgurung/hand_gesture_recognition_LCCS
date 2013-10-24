#include "tracking.h"

tracking::tracking(){
    KF.init(4,2,0);
    state = cv::Mat_<float>(4,1);
    processNoise = cv::Mat(4,1,CV_32F);
    measurement = cv::Mat_<float>(2,1);
    measurement.setTo(cv::Scalar(0));

    filter_init = false;
}

void tracking::initTracker(cv::Point & pt)
{
    KF.statePre.at<float>(0) = pt.x;
    KF.statePre.at<float>(1) = pt.y;
    KF.statePre.at<float>(2) = 0;
    KF.statePre.at<float>(3) = 0;
    KF.transitionMatrix = *(cv::Mat_<float>(4, 4) << 1,0,0,0,   0,1,0,0,  0,0,1,0,  0,0,0,1);

    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, cv::Scalar::all(1e-4));
    setIdentity(KF.measurementNoiseCov, cv::Scalar::all(1e-1));
    setIdentity(KF.errorCovPost, cv::Scalar::all(.1));

    filter_init = true;
}

cv::Point tracking::KFcycle(cv::Point &pointinfo)
{
    prediction = KF.predict();
    //cv::Point predictPt(prediction.at<float>(0), prediction.at<float>(1));
    measurement(0) = pointinfo.x;
    measurement(1) = pointinfo.y;
    //cv::Point measPt(KFtrack.measurement(0), KFtrack.measurement(1));

    estimated = KF.correct(measurement);

    cv::Point statePt(estimated.at<float>(0),estimated.at<float>(1));
    return( statePt );
}
