/***************************************************************************
                                    imageprocessingdialog.cpp
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#include "imageprocessingdialog.h"
#include "ui_imageprocessingdialog.h"

#include<QtCore>

ImageProcessingDialog::ImageProcessingDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    connect(this, SIGNAL(accepted()), this, SLOT(updateImageProcessingSettings()));
}

ImageProcessingDialog::~ImageProcessingDialog()
{

}

void ImageProcessingDialog::updateImageProcessingSettings()
{
    // Detector
    if(fastDetectorButton->isChecked())
        detectorSettingFlags.fastDetectorOn = true;
    else if(surfDetectorButton->isChecked())
        detectorSettingFlags.surfDetectorOn = true;
    else if(siftDetectorButton->isChecked())
        detectorSettingFlags.siftDetectorOn = true;
    else if(harrisDetectorButton->isChecked())
        detectorSettingFlags.harrisDetectorOn = true;

    //
    emit newImageProcessingSettings(detectorSettingFlags);

}
