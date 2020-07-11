#include "ventanamodojuego.h"
#include "ui_ventanamodojuego.h"
#include <QMediaPlayer>

#include <informacion.h>
extern infoArchivo infoUsuario;
extern QVector<infoArchivo> informacionJuego;

#include <QDialog> //

VentanaModoJuego::VentanaModoJuego(QWidget *parent) : QMainWindow(parent), ui(new Ui::VentanaModoJuego)
{
    ui->setupUi(this);
}

VentanaModoJuego::~VentanaModoJuego()
{
    delete ui;
}

void VentanaModoJuego::on_actionSobrePersonajes_triggered()
{
    QDialog *dialog = new QDialog;
    dialog->setWindowIcon(QIcon(":/iconos/iconW_nave.png"));
    dialog->setWindowTitle("Información de personajes");
    dialog->setGeometry(this->x(),this->y(),200,200);

                                /*
                                FALTA CUADRARLO PARA PONERLE LA IMAGEN CORRESPONDIENTE
                                A LA INFORMACIÓN DE LOS PERSONAJES.
                                */

    dialog->setModal(true);
    dialog->setVisible(true);
}

void VentanaModoJuego::on_modoMultijugador_clicked()
{
    infoUsuario.string1 = "<M>";                        //Modo multijugador
    infoUsuario.int1 = informacionJuego.at(0).int1;     //Le pasa el puntaje
    infoUsuario.int2 = informacionJuego.at(0).int2;     //Le pasa el nivel en el que se encuentra el usuario
    cambiarVentana();
}

void VentanaModoJuego::on_modoIndividual_clicked()
{
    infoUsuario.string1 = "<I>";    //Modo individual
    infoUsuario.int1 = informacionJuego.at(1).int1;     //Le pasa el puntaje
    infoUsuario.int2 = informacionJuego.at(1).int2;     //Le pasa el nivel en el que se encuentra el usuario
    cambiarVentana();
}

void VentanaModoJuego::cambiarVentana()
{
    for(unsigned short int n=0; n<informacionJuego.size(); n++)
    {
        qDebug() << informacionJuego.at(n).string1.c_str()  //Indica el modo de juego
                 << "\t" << informacionJuego.at(n).string2.c_str()  //Nombre del usuario
                 << "\t" << informacionJuego.at(n).int1     //Puntaje de la partida en curso
                 << "\t" << informacionJuego.at(n).int2;    //Nivel en el que se encuentra
    }
    wS.setGeometry(this->geometry());
    this->close();                  //Cierra Inicio de sesion/ registro
    wS.setVisible(true);            //Muestra ventana de elección de modo de juego
}
