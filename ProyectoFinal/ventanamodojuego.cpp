#include "ventanamodojuego.h"
#include "ui_ventanamodojuego.h"

VentanaModoJuego::VentanaModoJuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaModoJuego)
{
    ui->setupUi(this);
}

VentanaModoJuego::~VentanaModoJuego()
{
    delete ui;
}
