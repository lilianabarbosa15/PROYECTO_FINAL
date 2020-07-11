#include "ventanajuego.h"
#include "ui_ventanajuego.h"

#include <QMediaPlayer>
extern QMediaPlayer *musica;

VentanaJuego::VentanaJuego(QWidget *parent) : QMainWindow(parent), ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}

void VentanaJuego::on_actionMusica_triggered()
{
    if(musica->state() == QMediaPlayer::PlayingState)
        musica->stop();
    else
        musica->play();
}
