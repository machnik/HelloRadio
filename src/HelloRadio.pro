QT += core gui widgets

CONFIG += c++20

SOURCES += \
    javascript.cpp \
    main.cpp \
    mainwidget.cpp \
    player.cpp \
    streamplayerjs.cpp

HEADERS += \
    javascript.h \
    mainwidget.h \
    player.h \
    streamplayerjs.h

FORMS += \
    mainwidget.ui

wasm {
    INCLUDEPATH += emscripten\cache\sysroot\include
    DEPENDPATH += emscripten\cache\sysroot\include
}

RESOURCES += \
    resources.qrc
