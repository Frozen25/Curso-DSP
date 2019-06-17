#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T15:52:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaPlayer
TEMPLATE = app

LIBS += -lfftw3f -ljack -lsndfile -lGL

SOURCES += main.cpp\
        mainwindow.cpp \
    jack.cpp \
    dspsystem.cpp \
    controlvolume.cpp \
    filterdtmf.cpp \
    dtmfgenerator.cpp \
    filter.cpp \
    filter2.cpp \
    filter3.cpp \
    dtmffilter.cpp \
    filteradapter.cpp

HEADERS  += mainwindow.h \
            jack.h \
            processor.h \
            dspsystem.h \
    controlvolume.h \
    filterdtmf.h \
    dtmfgenerator.h \
    filter.h \
    filter2.h \
    filter3.h \
    dtmffilter.h \
    filteradapter.h

FORMS    += mainwindow.ui

RESOURCES +=

DISTFILES += \
    audiocheck.net_dtmf_1.wav
