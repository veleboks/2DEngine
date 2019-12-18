CONFIG += c++11 console
CONFIG -= app_bundle

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
else:unix: LIBS += -L$$PWD/SFML/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/SFML/include
DEPENDPATH += $$PWD/SFML/include


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Objects/button.cpp \
        Objects/enemy.cpp \
        Objects/player.cpp \
        Objects/unit.cpp \
        Scenes/game.cpp \
        Scenes/menu.cpp \
        engine.cpp \
        gameobject.cpp \
        globals.cpp \
        main.cpp \
        scene.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Objects/button.h \
    Objects/enemy.h \
    Objects/player.h \
    Objects/unit.h \
    Scenes/game.h \
    Scenes/menu.h \
    engine.h \
    gameobject.h \
    globals.h \
    scene.h
