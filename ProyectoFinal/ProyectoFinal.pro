#-------------------------------------------------
#
# Project created by QtCreator 2020-07-08T10:15:08
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        aliado.cpp \
        animacion.cpp \
        cuerpoanim.cpp \
        enemigo.cpp \
        escritor.cpp \
        juego.cpp \
        main.cpp \
        moneda.cpp \
        plataforma.cpp \
        meteorito.cpp \
        puntaje.cpp \
        ventanajuego.cpp \
        ventanalogin.cpp \
        ventanamodojuego.cpp \
        ventanaseleccionjuego.cpp

HEADERS += \
        aliado.h \
        animacion.h \
        bala.h \
        cuerpo.h \
        cuerpoanim.h \
        enemigo.h \
        escritor.h \
        informacion.h \
        juego.h \
        moneda.h \
        plataforma.h \
        meteorito.h \
        puntaje.h \
        ventanajuego.h \
        ventanalogin.h \
        ventanamodojuego.h \
        ventanaseleccionjuego.h

FORMS += \
        ventanajuego.ui \
        ventanalogin.ui \
        ventanamodojuego.ui \
        ventanaseleccionjuego.ui

RESOURCES += \
    detalles.qrc \
    escenas.qrc \
    historia.qrc \
    rec.qrc \
    sprites.qrc
