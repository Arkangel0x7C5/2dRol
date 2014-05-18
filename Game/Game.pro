#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T22:06:11
#
#-------------------------------------------------

QT       -= core gui
CONFIG += c++11

TARGET = Game
TEMPLATE = lib

DEFINES += GAME_LIBRARY

SOURCES += game.cpp \
    levelscene.cpp \
    tileset.cpp \
    tile.cpp \
    terrain.cpp \
    animateterrain.cpp \
    manager/terrainmanager.cpp \
    staticterrain.cpp \
    objectmodelmanager.cpp \
    character.cpp \
    configparser.cpp

HEADERS += game.h\
        game_global.h \
    levelscene.h \
    tileset.h \
    tile.h \
    terrain.h \
    animateterrain.h \
    manager/terrainmanager.h \
    staticterrain.h \
    objectmodelmanager.h \
    character.h \
    configparser.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Engine/release/ -lEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Engine/debug/ -lEngine
else:unix: LIBS += -L$$OUT_PWD/../Engine/ -lEngine

INCLUDEPATH += $$PWD/../Engine
DEPENDPATH += $$PWD/../Engine
