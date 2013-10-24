#-------------------------------------------------
#
# Project created by QtCreator 2013-03-02T11:03:06
#
#-------------------------------------------------

QT       += core gui

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \    
    tracking/tracking.cpp \
    Process_interface/usefulMathFunctions.cpp \
    Process_interface/processing.cpp \
    Process_interface/imageprocessingdialog.cpp \
    Process_interface/capture.cpp

HEADERS  += mainwindow.h \            
    tracking/tracking.h \
    Process_interface/usefulMathFunctions.h \
    Process_interface/Structure.h \
    Process_interface/processing.h \
    Process_interface/imageprocessingdialog.h \
    Process_interface/configure.h \
    Process_interface/capture.h

FORMS    += mainwindow.ui \
    imageprocessingdialog.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv

QT += testlib
