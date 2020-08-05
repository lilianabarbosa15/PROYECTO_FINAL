#ifndef VENTANASELECCIONJUEGO_H
#define VENTANASELECCIONJUEGO_H

#include <QMainWindow>
#include <QLabel>
#include "ventanajuego.h"

namespace Ui {
class VentanaSeleccionJuego;
}

class VentanaSeleccionJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaSeleccionJuego(QWidget *parent = nullptr);
    ~VentanaSeleccionJuego();
    VentanaJuego wJ;

private slots:
    void on_actionSobrePersonajes_triggered();
    void on_reiniciarJuego_clicked();
    void on_retomarJuego_clicked();

private:
    void cambiarVentana();

private:
    Ui::VentanaSeleccionJuego *ui;

};

#endif // VENTANASELECCIONJUEGO_H
