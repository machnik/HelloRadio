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
    stations.h \
    streamplayerjs.h

FORMS += \
    mainwidget.ui

wasm {
    INCLUDEPATH += D:\ems\emsdk\upstream\emscripten\cache\sysroot\include
    DEPENDPATH += D:\ems\emsdk\upstream\emscripten\cache\sysroot\include
}

RESOURCES += \
    resources.qrc
