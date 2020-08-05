#include "ventanaseleccionjuego.h"
#include "ui_ventanaseleccionjuego.h"
#include "juego.h"
#include <QDialog>

#include <escritor.h>
extern infoArchivo infoUsuario;
extern QVector<infoArchivo> informacionJuego;

extern QGraphicsScene *escena;  //Para dibujar la escena del juego en la que se encuentra el personaje
extern Juego *juego;

VentanaSeleccionJuego::VentanaSeleccionJuego(QWidget *parent) : QMainWindow(parent),  ui(new Ui::VentanaSeleccionJuego)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
}

VentanaSeleccionJuego::~VentanaSeleccionJuego()
{
    delete ui;
}

void VentanaSeleccionJuego::on_actionSobrePersonajes_triggered()
{
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

void VentanaSeleccionJuego::on_reiniciarJuego_clicked()
{
    infoUsuario.int1 = 0;
    infoUsuario.int2 = 0;

    if(infoUsuario.string1 == "<M>")
        informacionJuego.replace(0,infoUsuario);
    else
        informacionJuego.replace(1,infoUsuario);

    Escritor().guardarPartida(informacionJuego);
    cambiarVentana();
}

void VentanaSeleccionJuego::on_retomarJuego_clicked()
{
    if(infoUsuario.string1 == "<M>"){
        infoUsuario.int1 = informacionJuego.at(0).int1;
        infoUsuario.int2 = informacionJuego.at(0).int2;
    }
    else{
        infoUsuario.int1 = informacionJuego.at(1).int1;
        infoUsuario.int2 = informacionJuego.at(1).int2;
    }
    cambiarVentana();
}

void VentanaSeleccionJuego::cambiarVentana()
{
    wJ.setGeometry(this->geometry());
    this->close();                  //Cierra ventana de elección de la partida de juego
    wJ.setVisible(true);            //Muestra ventana de juego
    escena->setBackgroundBrush(Qt::lightGray);
    juego = new Juego();
}
