#include "ventanalogin.h"
#include <QApplication>

#include <QMediaPlayer>
QMediaPlayer *musica = new QMediaPlayer(); //Para manejar la musica desde diferentes ventanas

infoArchivo infoUsuario;                    //Contendrá la información del tipo de juego en el que se está durante toda la partida
QVector<infoArchivo> informacionJuego = {}; //Contendrá toda la información guardada en la base de datos actual

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaLogin wL;
    wL.setWindowIcon(QIcon(":/iconos/iconW_nave.png"));
    wL.show();

    return a.exec();
}
