#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T22:06:11
#
#-------------------------------------------------

QT       -= core gui

TARGET = Game
TEMPLATE = lib

DEFINES += GAME_LIBRARY

SOURCES += game.cpp

HEADERS += game.h\
        game_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
