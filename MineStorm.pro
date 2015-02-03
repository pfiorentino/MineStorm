#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T00:07:39
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineStorm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameboard.cpp \
    game.cpp \
    minestormgame.cpp \
    spaceship.cpp \
    life.cpp \
    mine.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    game.h \
    minestormgame.h \
    spaceship.h \
    life.h \
    mine.h

FORMS    +=

