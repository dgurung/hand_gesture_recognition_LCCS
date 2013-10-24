/***************************************************************************
                                    processing.cpp
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#include "processing.h"
#include <vector>
#include <QDebug>
#include <iostream>
#include <cmath>

#include <QtGui/QCursor>

using namespace std;

Processing::Processing(QObject *parent) :
    QObject(parent)
{

}


void Processing::updateImageProcessingFlags(struct DetectorSettingFlags d_SettingFlags)
{

}


bool Processing::detectFace()
{   
    faces.clear();
    cvtColor( Processedframe, frame_gray, CV_BGR2GRAY );
    //cv::equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );



    // Remove face from processing frame
    if(faces.size())
    {
        cv::Mat roi(Processedframe,faces[0]);
        roi_face = Scalar::all(0);
        roi.copyTo(roi_face);
        roi = Scalar::all(0);
        return true;
    }
    else
        return false;
}


bool Processing::detectHandFist()
{
    hands.clear();
    cvtColor( Processedframe, frame_gray, CV_BGR2GRAY );
    hand_cascade.detectMultiScale( frame_gray, hands, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, Size(40,40) );

    //    if(hands.size())
    //    {
    //        Point center( hands[0].x + hands[0].width*0.5, hands[0].y + hands[0].height*0.5 );
    //        ellipse( Processedframe, center, Size( hands[0].width*0.5, hands[0].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    //    }
//    for( int i = 0; i < hands.size(); i++ )
//    {
//        Point center( hands[i].x + hands[i].width*0.5, hands[i].y + hands[i].height*0.5 );
//        ellipse( Processedframe, center, Size( hands[i].width*0.5, hands[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 0 ), 4, 8, 0 );
//    }
    if(!hands.size())
        return false;
    else
        return true;
}


bool Processing::detectHandPalm()
{
    handsPalm.clear();
    cvtColor( Processedframe, frame_gray, CV_BGR2GRAY );
    hand_palm_cascade.detectMultiScale( frame_gray, handsPalm, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, Size(40,40) );

    //    if(handsPalm.size())
    //    {
    //                Point center( handsPalm[0].x + handsPalm[0].width*0.5, handsPalm[0].y + handsPalm[0].height*0.5 );
    //                ellipse( Processedframe, center, Size( handsPalm[0].width*0.5, handsPalm[0].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    //    }
//    for( int i = 0; i < handsPalm.size(); i++ )
//    {
//        Point center( handsPalm[i].x + handsPalm[i].width*0.5, handsPalm[i].y + handsPalm[i].height*0.5 );
//        ellipse( Processedframe, center, Size( handsPalm[i].width*0.5, handsPalm[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
//    }
    if(!handsPalm.size())
        return false;
    else
        return true;
}

/* Detect Fingers in Log Chromatic Color Space */
bool Processing::detectFingerAndCentroidInOpenPalm(cv::Mat& frame)
{
    /**************    *********/
    // Find contours
    cv::findContours( mask.clone(), contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_TC89_KCOS, Point(0, 0) );


    // Find Convex hull and convexity defects
    hull.resize(contours.size());
    hullsI.resize(contours.size());
    convdefect.resize(contours.size());

    //qDebug() << "hull capacity" << hull.capacity();
    for( int i = 0; i < contours.size(); i++ )
    {
        convexHull( Mat(contours[i]), hull[i], false);
        convexHull( Mat(contours[i]), hullsI[i], false);
        if(hullsI[i].size() > 3 )
            convexityDefects(contours[i],hullsI[i],convdefect[i]);
    }

    //cv::RNG rng = 12345;

    // Draw contours + hull results
    drawing = Mat::zeros( frame.size(), CV_8UC3 );

    //
    //    for( int i = 0; i< contours.size(); i++ )
    //    {
    //        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    //        drawContours( drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
    //        drawContours( drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
    //    }

    /********************************************/
    /*  Compute number of fingers using convexity Defects
    */
    Point vector1, vector2;
    float length1, length2;
    float angle;
    float dotproduct;

    bool testhandopen =false;

    for( int i = 0; i< contours.size(); i++ )
    {
        size_t count = contours[i].size();
        if( count <60 )
            continue;

        float depth = 0;
        int defect_counter = 0;
        vector<Vec4i>::iterator d=convdefect[i].begin();
        while( d!=convdefect[i].end() ) {
            Vec4i& v=(*d);
            int startidx=v[0]; Point ptStart( contours[i][startidx] );
            int endidx=v[1]; Point ptEnd( contours[i][endidx] );
            int faridx=v[2]; Point ptFar( contours[i][faridx] );
            depth = v[3] / 256; //
            //if(depth > 30)

            //Compute angle between fingers.
            vector1.x = ptStart.x - ptFar.x;    vector1.y = ptStart.y - ptFar.y;
            vector2.x = ptEnd.x - ptFar.x;      vector2.y = ptEnd.y - ptFar.y;

            dotproduct = vector1.x * vector2.x + vector1.y * vector2.y;
            length1 = sqrtf((vector1.x*vector1.x)+(vector1.y*vector1.y));
            length2 = sqrtf((vector2.x*vector2.x)+(vector2.y*vector2.y));
            angle = fabs(dotproduct/(length1*length2));

            //qDebug() << "Angle: " << angle;

            if(angle > 0.5 && depth >30){
                defect_counter++;
                /*
                line( drawing, ptStart, ptEnd, Scalar(0,255,0), 1 );
                line( drawing, ptStart, ptFar, Scalar(0,255,0), 1 );
                line( drawing, ptEnd, ptFar, Scalar(0,255,0), 1 );
                circle( drawing, ptFar,   4, Scalar(255,0,0), 2 );
                circle(drawing, ptStart,4,Scalar(0,0,255),2);*/
            }
            d++;
        }


        // Tracking finger using KF
        if(defect_counter>=2){
            testhandopen = true;

            // Find moment of current contour
            cv::Moments moment = moments((cv::Mat)contours[i]);
            double area = moment.m00;

            trackingpt.x = moment.m10/area;
            trackingpt.y = moment.m01/area;
        }
    }



    // free memory
    vector<vector<Point> >().swap(hull);
    vector<vector<int> >().swap(hullsI);
    vector<vector<Vec4i> >().swap(convdefect);

    return testhandopen;
}


/* Skin Probability Mapping */
void Processing::spm_predict(const Mat &img_hsv, Mat &output_mask)
{
    Mat_<Vec3f> hsv_ = img_hsv.reshape(3,img_hsv.rows*img_hsv.cols);
    Mat_<uchar> result_mask(hsv_.size());

    for(int i=0; i < hsv_.rows; i++ )
    {
        float h = hsv_(i)[0]/255.0;
        float s = hsv_(i)[1]/255.0;
        float skin_h_pr = normalPdf(h, h_sk_mean, h_sk_std);     // P(H|skin)
        float skin_s_pr = normalPdf(s, s_sk_mean, s_sk_std);     // P(S|skin)

        float non_skin_h_pr = normalPdf(h, h_nsk_mean, h_nsk_std);   // P(H|~skin)
        float non_skin_s_pr = normalPdf(s, s_nsk_mean, s_nsk_std);   // P(S|~skin)

        // P(HS|skin)
        float prob_skin = skin_h_pr * skin_s_pr;
        // P(HS|~skin)
        float prob_not_skin = non_skin_h_pr * non_skin_s_pr;

        if((prob_skin/prob_not_skin) > theta_thresh)
            result_mask(i) = 255;
        else
            result_mask(i) = 0;
    }

    output_mask = result_mask.reshape(1, img_hsv.rows);
}



void Processing::subtractbackground(Mat &frame)
{
    if (~frame.empty()){
        if(1){


            if( background.empty()){

                //imwrite("background.jpg", frame);

                background = frame.clone();
                //cv::putText(background, "okokok", cv::Point(10,20), 1 ,0.2, cv::Scalar(255,0,0));
                //frame.copyTo(background);
                //background = imread("background.jpg",1);
                Processedframe = Scalar::all(0);
                cout <<"true" << endl;
            }
        }
    }
    // compute difference between current image and background
    cv::absdiff(background,frame,Processedframe);

    //Processedframe.convertTo(background, CV_8UC3);

    //    float learningRate = 0.1;
    //    cv::accumulateWeighted(frame, background, learningRate);
}



void Processing::takeBGImage()
{

}



string Processing::GestureFromBuffer(struct GesturePresenceFlags gestureFlags)
{


    string gesture("  ");
    if(frameGestureBufferIdx.size() < FRAME_BUFFER_SIZE)
    {
        if(gestureFlags.handopen) frameGestureBufferIdx.push_back(openpalm);
        else if(gestureFlags.handPresent) frameGestureBufferIdx.push_back(fist);
        else if(gestureFlags.handsPalmPresent) frameGestureBufferIdx.push_back(palm);
    }
    //cout << frameGestureBufferIdx.size() << endl;
    if(frameGestureBufferIdx.size() == FRAME_BUFFER_SIZE)
    {
        vector<int>::iterator itr = frameGestureBufferIdx.begin();
        int openpalm_cnt =0; int fist_cnt = 0; int palm_cnt = 0;

        while(itr!= frameGestureBufferIdx.end())
        {
            if(*itr == openpalm)
                openpalm_cnt +=1;
            else if(*itr == fist)
                fist_cnt += 1;
            else if(*itr == palm)
                palm_cnt += 1;

            itr++;
        }

        // Select the highest gesture in the buffer
        if(fist_cnt > openpalm_cnt && fist_cnt > palm_cnt)
            gesture = "Fist";
        else if(palm_cnt > fist_cnt && palm_cnt > openpalm_cnt)
            gesture =  "Palm";
        else
            gesture = "OpenHand";

        frameGestureBufferIdx.erase(frameGestureBufferIdx.begin());
        //cout << frameGestureBufferIdx.size() << endl;
    }
    return gesture;
}



/********  Process  *********/
void Processing::updateOriginalFrameForProcessing(cv::Mat &frame)
{
    Processedframe = frame ;

    //subtractbackground(frame);

    // apply face detection algorithm and remove
    bool facePresent = detectFace();
    gestureFlag.handPresent = detectHandFist();
    gestureFlag.handsPalmPresent = detectHandPalm();

    if(gestureFlag.handPresent != true || gestureFlag.handsPalmPresent != true) // Possibility of open palm
    {
        /* Soften image */
        cv::GaussianBlur(Processedframe,Processedframe, cv::Size(3,3), 2,2, cv::BORDER_DEFAULT );

        /* Remove some impulsive noise */
        cv::medianBlur(Processedframe, Processedframe, 7);

        cv::split(Processedframe, rgb);

        Mat_<Vec3f> bgr_ = Processedframe.clone().reshape(3,Processedframe.rows*Processedframe.cols);
        Mat_<uchar> result_mask(bgr_.size());

        /* Threshold in Log Chromatic Color Space   */
        for(int i=0; i < bgr_.rows; i++ )
        {
            float b = bgr_(i)[0]/1.0;
            float g = bgr_(i)[1]/1.0;
            float r = bgr_(i)[2]/1.0;
            float log_rg = log(r/g);     // P(H|skin)
            float log_bg = log(b/g);     // P(S|skin)

            if( (log_rg >= 0.15 && log_rg<=1.1) && log_bg >= -4 && log_bg<0.3 )
                result_mask(i) = 255;
            else
                result_mask(i) = 0;
        }

        mask = result_mask.reshape(1, Processedframe.rows);


        /* Detect Finger and Centroid of hand using mask */
        gestureFlag.handopen = this->detectFingerAndCentroidInOpenPalm(frame);

        /* TRack detected hand  */
        if(gestureFlag.handopen)
        {
            // Initialize Kalman Filter once.
            if(!KFtrack.filter_init)
                KFtrack.initTracker(trackingpt);

            //Track contour centroid using Kalman Filter
            trackedpt = KFtrack.KFcycle(trackingpt);

            // show tracked point
            circle(drawing, trackingpt, 5, Scalar(0,255,0), -1 , 8);
            circle(drawing, trackingpt, 8, Scalar(255,0,0), 0 , 8);

        }
    }

    std::string gesture = GestureFromBuffer(gestureFlag);
    cv::putText(drawing, gesture, cv::Point(30,30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(200,200,250), 1, CV_AA);

    /*********************              Display             *******************************/

    /** convert to RGB for display **/
    cv::cvtColor(Processedframe, Processedframe, CV_BGR2RGB );
    QImage qimgProcessed(( uchar*)drawing.data, drawing.cols, drawing.rows, drawing.step, QImage::Format_RGB888);

    QImage qimgProcessIntermediate(( uchar*)mask.data, mask.cols, mask.rows, mask.step, QImage::Format_Indexed8);

    // Emit image processed frame to output gui screeen
    emit(newProcessedFrame(qimgProcessed));
    emit(newProcessIntermediateFrame(qimgProcessIntermediate));

    gestureFlag.handPresent = false;
    gestureFlag.handsPalmPresent = false;
    gestureFlag.handopen =false;
}
