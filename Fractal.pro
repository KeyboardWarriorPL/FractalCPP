######################################################################
# Automatically generated by qmake (3.1) Fri May 3 11:13:26 2019
######################################################################

TEMPLATE = app
TARGET = Fractal
INCLUDEPATH += .
DESTDIR = ./bin

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt

# Input
HEADERS += FComplex.h Polynomial.h Julia.h
FORMS += front.ui
SOURCES += main.cpp FComplex.cpp Polynomial.cpp Julia.cpp

LIBS += -L/usr/local/lib

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
