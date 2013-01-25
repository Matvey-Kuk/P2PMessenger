#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T23:10:39
#
#-------------------------------------------------

QT       += core gui network

TARGET = P2PMessenger2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tunnelwarlock.cpp \
    p2porganizer.cpp \
    socialrelationsmanager.cpp \
    router.cpp \
    paranoid.cpp \
    boxwithwires.cpp \
    connection.cpp \
    messengerconnectionprovider.cpp \
    privateconnectionfunctionality.cpp \
    publicconnectionfunctional.cpp \
    server.cpp \
    globalcondition.cpp

HEADERS  += mainwindow.h \
    tunnelwarlock.h \
    p2porganizer.h \
    socialrelationsmanager.h \
    router.h \
    paranoid.h \
    boxwithwires.h \
    connection.h \
    messengerconnectionprovider.h \
    privateconnectionfunctionality.h \
    publicconnectionfunctional.h \
    server.h \
    globalcondition.h

FORMS    += mainwindow.ui
