#include "ventanalogin.h"
#include "ventanajuego.h"
#include "juego.h"
#include <QApplication>


Juego *juego;
QGraphicsScene *escena;  //La escena del juego como tal
infoArchivo infoUsuario;                    //Contendrá la información del tipo de juego en el que se está durante toda la partida
QVector<infoArchivo> informacionJuego = {}; //Contendrá toda la información guardada en la base de datos actual

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaLogin wL;
    wL.setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
    wL.show();

    return a.exec();
}
