#ifndef VENTANASELECCIONJUEGO_H
#define VENTANASELECCIONJUEGO_H

#include <QMainWindow>
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
    Ui::VentanaSeleccionJuego *ui;

    void cambiarVentana();
};

#endif // VENTANASELECCIONJUEGO_H
