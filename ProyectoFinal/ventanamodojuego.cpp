#include "ventanamodojuego.h"
#include "ui_ventanamodojuego.h"
#include <QMediaPlayer>
extern QMediaPlayer *musica;

#include <QDialog>

VentanaModoJuego::VentanaModoJuego(QWidget *parent) : QMainWindow(parent), ui(new Ui::VentanaModoJuego){ ui->setupUi(this); }

VentanaModoJuego::~VentanaModoJuego(){ delete ui; }

void VentanaModoJuego::on_actionSonido_triggered()
{
    if(musica->state() == QMediaPlayer::PlayingState)
        musica->stop();
    else
        musica->play();
}

void VentanaModoJuego::on_actionSobrePersonajes_triggered()
{
    QDialog *dialog = new QDialog;
    dialog->setWindowIcon(QIcon(":/iconos/iconW_nave.png"));
    dialog->setWindowTitle("Información de personajes");
    dialog->setGeometry(this->x(),this->y(),200,200);
                                /*
                                YA LE DI FORMA Y POSICIÓN A LA VENTANA FALTA CUADRARLO PARA
                                PONERLE LA IMAGEN CORRESPONDIENTE A LA INFORMACIÓN DE LOS
                                PERSONAJES.
                                HAY QUE CONFIGURARLO PARA QUE SE DESACTIVE MOMENTANEAMENTE
                                LA VENTANA PRINCIPAL.
                                */
    dialog->setVisible(true);
}

void VentanaModoJuego::on_modoMultijugador_clicked()
{

}

void VentanaModoJuego::on_modoIndividual_clicked()
{

}
