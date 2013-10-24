/***************************************************************************
                                    UsefulMathFunctions.cpp
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

# include "usefulMathFunctions.h"

# include <cmath>

using namespace std;
float normalPdf(const float x, const float m, const float s)
{
    static const float inv_sqrt_2pi = 0.3989422804014327;
    float a = (x - m) / s;

    return inv_sqrt_2pi / s * exp(-0.5 * a * a);
}


