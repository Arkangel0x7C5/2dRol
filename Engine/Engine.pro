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
    camera.cpp \
    commandmanager.cpp \
    imagemanager.cpp \
    scene.cpp \
    quadtree.cpp \
    Interfaces/animation.cpp \
    timer.cpp \
    Interfaces/clonable.cpp \
    Interfaces/objectfactory.cpp \
    Interfaces/property.cpp \
    Interfaces/component.cpp \
    Component/graphiccomponent.cpp \
    Component/controllercomponent.cpp \
    Component/physicscomponent.cpp \
    Component/commandcomponent.cpp \
    Physics/basicphysicscomponent.cpp \
    Controller/playercontrollercomponent.cpp \
    Controller/iacontrollercomponent.cpp

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
    camera.h \
    commandmanager.h \
    imagemanager.h \
    scene.h \
    quadtree.h \
    Interfaces/animation.h \
    timer.h \
    Interfaces/clonable.h \
    Interfaces/objectfactory.h \
    Interfaces/property.h \
    Interfaces/component.h \
    Component/graphiccomponent.h \
    Component/controllercomponent.h \
    Component/physicscomponent.h \
    Component/commandcomponent.h \
    Physics/basicphysicscomponent.h \
    Controller/playercontrollercomponent.h \
    Controller/iacontrollercomponent.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -lGL -lglut -lglapi -lEGL


unix|win32: LIBS += -lSDL -lSDL_image
