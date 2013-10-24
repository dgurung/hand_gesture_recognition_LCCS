#ifndef TRACKING_H
#define TRACKING_H

#include <opencv2/core/core.hpp>
#include <opencv2/video/tracking.hpp>

#define dyn 2;

class tracking{
public:
    tracking();
private:
    cv::KalmanFilter KF;
    cv::Mat_<float> state;
    cv::Mat processNoise;
    cv::Mat_<float> measurement;  

    cv::Mat prediction;
    cv::Mat estimated;

public:
    bool filter_init;

    cv::Point KFcycle(cv::Point &);
    void initTracker(cv::Point &);
};

#endif // TRACKING_H
