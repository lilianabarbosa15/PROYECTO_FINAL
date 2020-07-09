#ifndef VENTANALOGIN_H
#define VENTANALOGIN_H

#include "ventanamodojuego.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QIcon>
using namespace std;

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
    string name_fichero, password_fichero;
    const char v_evaluar[11] = {'|','/','<','>','*',' ','?','*',':','\\','\"'};
    bool estadoName = false, estadoPassword = false;
    QMessageBox msgBox;

    bool verificarDato();    //Verifica si es valido cada dato ingresado
    void leerArchivo();      //Busca los datos ingresados por el usuario en un archivo predeterminado
    void registrarUsuario(); //Registra un nuevo usuario al sistema
    void cambiarVentana();   //Cierra la ventana actual y muestra otra

};

#endif // VENTANALOGIN_H
