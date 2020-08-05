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
    //Se muestra información sobre personajes de la historia.
    QDialog *dialog = new QDialog();
    dialog->setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
    dialog->setWindowTitle("Players information");
    dialog->setGeometry(this->x(),this->y(),500,500);
    dialog->setFixedSize(500,500);
    dialog->setStyleSheet("background-color:black;");
    dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QLabel *label = new QLabel(dialog);
    label->setPixmap(QPixmap(":/info/Informacion/Personajes_Desc_.jpg").scaled(500,500));

    dialog->setModal(true);
    dialog->setVisible(true);
}

void VentanaModoJuego::on_modoMultijugador_clicked()
{
    //Opción multijugador: registro de la elección del jugador.
    infoUsuario.string1 = "<M>";                        //Modo multijugador
    infoUsuario.int1 = informacionJuego.at(0).int1;     //Le pasa el puntaje
    infoUsuario.int2 = informacionJuego.at(0).int2;     //Le pasa el nivel en el que se encuentra el usuario
    cambiarVentana();
}

void VentanaModoJuego::on_modoIndividual_clicked()
{
    //Opción individual: registro de la elección del jugador.
    infoUsuario.string1 = "<I>";    //Modo individual
    infoUsuario.int1 = informacionJuego.at(1).int1;     //Le pasa el puntaje
    infoUsuario.int2 = informacionJuego.at(1).int2;     //Le pasa el nivel en el que se encuentra el usuario
    cambiarVentana();
}

void VentanaModoJuego::cambiarVentana()
{
    //Cambio a ventana de selección de juego (reiniciar/continuar partida)
    wS.setGeometry(this->geometry());
    this->close();                  //Cierra Inicio de sesion/ registro
    wS.setVisible(true);            //Muestra ventana de elección de selección de juego
}
