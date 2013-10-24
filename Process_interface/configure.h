/***************************************************************************
                                    configure.h
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#ifndef CONFIGURE_H
#define CONFIGURE_H


#define DEFAULT_CAMERA_DEV_NO 0

#define DEFAULT_SURF_DETECTOR_SETTING true
#define DEFAULT_SURF_DESCRIPTOR_SETTING true
#define DEFAULT_MATCHER_SETTING true

// camera width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

// Values learned for Skin Probability Map in HS color space
// Tr
static const float h_sk_mean = 0.220190976658194,   h_sk_std = 0.340885345150450;
static const float s_sk_mean = 0.315681297063194,   s_sk_std = 0.0756408700330955;

static const float h_nsk_mean = 0.402209473014649,	h_nsk_std = 0.314400473858617;
static const float s_nsk_mean = 0.225959613187678,  s_nsk_std = 0.181355835772267;

float const theta_thresh = 2.0;

const int FRAME_BUFFER_SIZE = 10;
#endif // CONFIGURE_H
