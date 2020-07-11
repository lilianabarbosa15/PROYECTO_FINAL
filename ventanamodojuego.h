#ifndef VENTANAMODOJUEGO_H
#define VENTANAMODOJUEGO_H

#include <QMainWindow>
#include "ventanaseleccionjuego.h"

namespace Ui { class VentanaModoJuego; }

class VentanaModoJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaModoJuego(QWidget *parent = nullptr);
    ~VentanaModoJuego();
    VentanaSeleccionJuego wS;

private slots:
    void on_actionSobrePersonajes_triggered();
    void on_modoMultijugador_clicked();
    void on_modoIndividual_clicked();

private:
    Ui::VentanaModoJuego *ui;

    void cambiarVentana();
};

#endif // VENTANAMODOJUEGO_H
