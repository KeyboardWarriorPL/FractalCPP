TEMPLATE = app
TARGET = Fractal
DESTDIR = ./bin

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS +=
SOURCES += main.cpp
FORMS += x.ui

LIBS += -L/usr/local/lib -lmath