#-------------------------------------------------
#
# Project created by QtCreator 2017-04-29T17:55:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorTheGrid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    square.cpp \
    gridupdateevent.cpp \
    solverthread.cpp \
    renderthread.cpp

HEADERS  += mainwindow.h \
    square.h \
    gridupdateevent.h \
    solverthread.h \
    renderthread.h

FORMS    += mainwindow.ui
