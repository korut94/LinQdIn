#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T19:24:02
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinQedIn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    utente.cpp \
    info.cpp \
    smartclass.cpp \
    rete.cpp \
    database.cpp \
    sortgrouputente.cpp

HEADERS  += mainwindow.h \
    utente.h \
    info.h \
    smartclass.h \
    rete.h \
    sortlist.h \
    database.h \
    sortgrouputente.h

FORMS    += mainwindow.ui
