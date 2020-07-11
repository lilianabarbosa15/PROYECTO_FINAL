#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QMainWindow>

namespace Ui {
class VentanaJuego;
}

class VentanaJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaJuego(QWidget *parent = nullptr);
    ~VentanaJuego();

private slots:
    void on_actionMusica_triggered();

private:
    Ui::VentanaJuego *ui;
};

#endif // VENTANAJUEGO_H
