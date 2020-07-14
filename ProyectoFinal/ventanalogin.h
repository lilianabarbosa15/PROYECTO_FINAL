#ifndef VENTANALOGIN_H
#define VENTANALOGIN_H

#include "ventanamodojuego.h"
#include <QMainWindow>
#include <QIcon>
using namespace std;

#include <QMessageBox>
#include "informacion.h"

namespace Ui { class VentanaLogin; }

class VentanaLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaLogin(QWidget *parent = nullptr);
    ~VentanaLogin();
    VentanaModoJuego wM;

private slots:
    void on_nuevoUsuario_clicked();
    void on_existeUsuario_clicked();
    void on_actionNombresValidos_triggered();
    void on_actionClavesValidas_triggered();

private:
    Ui::VentanaLogin *ui;
    string name_ingresado, password_ingresado;
    QVector<infoArchivo> informacionU = {};
    QMessageBox msgBox;
    const char v_evaluar[11] = {'|','/','<','>','*',' ','?','*',':','\\','\"'};
    bool estadoName = false, estadoPassword = false;

    bool verificarDato();    //Verifica si es valido cada dato ingresado
    void cambiarVentana();   //Cierra la ventana actual y muestra otra
};

#endif // VENTANALOGIN_H
