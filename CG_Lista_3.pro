#-------------------------------------------------
#
# Project created by QtCreator 2011-11-10T10:28:06
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = CG_Lista_3
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qglwidgetcustom.cpp \
    vector3.cpp \
    point3.cpp \
    matrix4.cpp \
    torusobject.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    qglwidgetcustom.h \
    vector3.h \
    point3.h \
    matrix4.h \
    object.h \
    camera.h \
    torusobject.h

FORMS    += mainwindow.ui

LIBS += -lglut
