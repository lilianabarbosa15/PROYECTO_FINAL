#ifndef VENTANAMODOJUEGO_H
#define VENTANAMODOJUEGO_H

#include <QMainWindow>

namespace Ui {
class VentanaModoJuego;
}

class VentanaModoJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaModoJuego(QWidget *parent = nullptr);
    ~VentanaModoJuego();

private:
    Ui::VentanaModoJuego *ui;
};

#endif // VENTANAMODOJUEGO_H
