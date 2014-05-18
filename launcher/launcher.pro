TEMPLATE = app

CONFIG +=c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Engine/release/ -lEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Engine/debug/ -lEngine
else:unix: LIBS += -L$$OUT_PWD/../Engine/ -lEngine

INCLUDEPATH += $$PWD/../Engine
DEPENDPATH += $$PWD/../Engine

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Game/release/ -lGame
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Game/debug/ -lGame
else:unix: LIBS += -L$$OUT_PWD/../Game/ -lGame

INCLUDEPATH += $$PWD/../Game
DEPENDPATH += $$PWD/../Game
