#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T15:38:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CyberSecurity
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbmanager.cpp \
    user.cpp \
    admin.cpp \
    date.cpp

HEADERS  += mainwindow.h \
    dbmanager.h \
    user.h \
    admin.h \
    date.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
