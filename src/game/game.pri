INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src
RESOURCES += $$PWD/game.qrc
DEFINES += KAJ_GAME_LIB

HEADERS += \
    $$PWD/src/gridmap.h \
    $$PWD/src/movementanimation.h \
    $$PWD/src/rotateanimation.h \
    $$PWD/src/gridmap_p.h \
    $$PWD/src/speedanimation.h \
    $$PWD/src/speedanimation_p.h \
    $$PWD/src/kajgameplugin.h

SOURCES += \
    $$PWD/src/gridmap.cpp \
    $$PWD/src/movementanimation.cpp \
    $$PWD/src/rotateanimation.cpp \
    $$PWD/src/speedanimation.cpp \
    $$PWD/src/kajgameplugin.cpp
