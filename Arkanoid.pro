#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16M5:28:33
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = let
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    gamewidget.cpp \
    state_load.cpp \
    state_menu.cpp \
    state_game.cpp \
    state_score.cpp \
    paddle.cpp \
    ball.cpp \
    block.cpp

HEADERS  += \
    game.h \
    gamewidget.h \
    state.h \
    state_menu.h \
    state_load.h \
    state_game.h \
    state_score.h \
    paddle.h \
    ball.h \
    block.h

RESOURCES += \
    resource.qrc

SUBDIRS += \
    ../../../Think/let_petruniv/let.pro \
    ../_Arconoid/Arkanoid.pro

DISTFILES += \
    ../build-AST-Desktop_Qt_5_4_0_MinGW_32bit-Release/game.txt \
    ../build-AST-Desktop_Qt_5_4_0_MinGW_32bit-Release/topscore.txt \
    ../build-AST-Desktop_Qt_5_4_0_MinGW_32bit-Release/saves.xml
