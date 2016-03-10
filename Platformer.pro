#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T14:54:29
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tmp
TEMPLATE = app

CONFIG += c++14

SOURCES += src\main.cpp\
        src\MainWidget.cpp \
    src/RenderWidget.cpp

HEADERS  += src\MainWidget.h \
    src/RenderWidget.h

FORMS    += ui\MainWidget.ui
