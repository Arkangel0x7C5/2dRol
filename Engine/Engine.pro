#-------------------------------------------------
#
# Project created by QtCreator 2014-03-29T12:41:35
#
#-------------------------------------------------

QT       -= core gui

TARGET = Engine
TEMPLATE = lib

DEFINES += ENGINE_LIBRARY

SOURCES += engine.cpp

HEADERS += engine.h\
        engine_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
