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
    database.cpp \
    sortgrouputente.cpp \
    hashgrouputente.cpp \
    smartptr_utente.cpp

HEADERS  += mainwindow.h \
    utente.h \
    info.h \
    smartclass.h \
    sortlist.h \
    database.h \
    sortgrouputente.h \
    hashgrouputente.h \
    smartptr_utente.h

FORMS    += mainwindow.ui
