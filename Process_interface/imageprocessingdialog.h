/***************************************************************************
                                    imageprocessingdialog.h
                             -------------------
    update               : 2013-06-15
    copyright            : (C) 2002 by Deepak Gurung
    email                : dpaq.grg@gmail.com

 ***************************************************************************/

#ifndef IMAGEPROCESSINGDIALOG_H
#define IMAGEPROCESSINGDIALOG_H

#include <QDialog>

#include "ui_imageprocessingdialog.h"

#include "Structure.h"

namespace Ui {
class ImageProcessingDialog;
}

class ImageProcessingDialog : public QDialog, Ui::ImageProcessingDialog
{
    Q_OBJECT
    
public:
    explicit ImageProcessingDialog(QWidget *parent = 0);
    ~ImageProcessingDialog();

    struct DetectorSettingFlags detectorSettingFlags;

public slots:
    void updateImageProcessingSettings();

signals:
    void newImageProcessingSettings(struct DetectorSettingFlags d_SettingsFlags);
};

#endif // IMAGEPROCESSINGDIALOG_H
