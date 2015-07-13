#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T21:50:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT1024
TEMPLATE = app


SOURCES += main.cpp\
        BoardView.cpp \
    mytile.cpp \
    board.cpp \
    game.cpp \
    observable.cpp \
    observer.cpp

HEADERS  += BoardView.h \
    mytile.h \
    game.h \
    board.h \
    observable.h \
    observer.h

FORMS    +=
