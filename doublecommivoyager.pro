#-------------------------------------------------
#
# Project created by QtCreator 2017-10-08T12:40:05
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = doublecommivoyager
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    algorythm.cpp \
    results.cpp

HEADERS  += gui.h \
    algorythm.h \
    results.h

FORMS    += gui.ui \
    results.ui
