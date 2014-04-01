#-------------------------------------------------
#
# Project created by QtCreator 2014-03-29T12:41:35
#
#-------------------------------------------------

QT       -= core gui

CONFIG +=c++11

TARGET = Engine
TEMPLATE = lib

DEFINES += ENGINE_LIBRARY

SOURCES += engine.cpp \
    drawable.cpp \
    cuadricula.cpp \
    gameobject.cpp \
    event.cpp \
    service.cpp \
    Event/keyboarevent.cpp \
    Interfaces/command.cpp \
    Event/mouseevent.cpp \
    view.cpp \
    camera.cpp

HEADERS += engine.h\
        engine_global.h \
    drawable.h \
    cuadricula.h \
    gameobject.h \
    event.h \
    service.h \
    Event/keyboarevent.h \
    Interfaces/command.h \
    Event/mouseevent.h \
    view.h \
    camera.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -lGL -lglut -lglapi -lEGL
