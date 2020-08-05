#include "ventanalogin.h"
#include "ui_ventanalogin.h"
#include "escritor.h"
#include <fstream>

extern infoArchivo infoUsuario;
extern QVector<infoArchivo> informacionJuego;

#include <QDebug> //

VentanaLogin::VentanaLogin(QWidget *parent) : QMainWindow(parent), ui(new Ui::VentanaLogin)
{
    ui->setupUi(this);
    msgBox.setWindowTitle(" ");
    msgBox.setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
    informacionU = Escritor().leerArchivo("USUARIOS");  //Se pasan los datos de las contraseñas y los nombres a un vector
}

VentanaLogin::~VentanaLogin()
{
    delete ui;
}

void VentanaLogin::on_nuevoUsuario_clicked()
{
    //Creación de nuevo usuario.
    name_ingresado = (ui->name->text()).toStdString();
    password_ingresado = (ui->password->text()).toStdString();

    if(verificarDato()==true){
        estadoName = false;
        for(int i=0; i<informacionU.size(); i++){
            if( informacionU.at(i).string1 == name_ingresado ){
                estadoName = true;
                break;
            }
        }

        if(estadoName == false){                                 //El nombre no se encontró
            Escritor().registrarUsuario(name_ingresado, password_ingresado);
            cambiarVentana();
        }
        else{
            msgBox.setText("USER ALREADY EXIST");
            msgBox.exec();
        }
    }
    else{
        msgBox.setText("DATA ERROR");
        msgBox.exec();
    }
}

void VentanaLogin::on_existeUsuario_clicked()
{
    //Inicio de sesión con usuario registrado.
    name_ingresado = (ui->name->text()).toStdString();
    password_ingresado = (ui->password->text()).toStdString();

    if(name_ingresado!="" && password_ingresado!=""){
        for(int i=0; i<informacionU.size(); i++){
            estadoName = false;                 //Supone que el nombre NO está guardado
            estadoPassword = false;             //Supone que la contraseña NO está guardada

            if(name_ingresado == informacionU.at(i).string1){
                estadoName = true;
                if (password_ingresado == informacionU.at(i).string2)
                    estadoPassword = true;
                break;
            }
        }
        if(estadoName==false || estadoPassword==false){
            msgBox.setText("INCORRECT PASSWORD OR USERNAME");
            msgBox.exec();
        }
        else
            cambiarVentana();
    }
    else{
        msgBox.setText("FILL THE BLANKS");
        msgBox.exec();
    }
}

bool VentanaLogin::verificarDato()
{
    //Verificación de validez de input.
    if(password_ingresado!="" && name_ingresado!=""){
        for(unsigned short int v=0; v< sizeof(v_evaluar); v++){  //Verifica nombre
            for(unsigned int n=0; n<name_ingresado.size(); n++){
                if(*(v_evaluar+v) == name_ingresado.at(n))
                    return false;                                   //Uno de los caracteres del nombre ingresado no es valido
            }
        }
        for(unsigned int c=0; c<password_ingresado.size(); c++){ //Verifica contraseña
            if(password_ingresado.at(c)==' ')
                return false;                                       //La contraseña contiene espacios
        }
    }
    else
        return false;                                               //No se ingresaron datos
    return true;                                                    //Nombre correcto
}

void VentanaLogin::cambiarVentana()
{
    //Cambiar a ventana de modo jugador.
    infoUsuario.string2 = name_ingresado;
    informacionJuego = Escritor().leerArchivo(infoUsuario.string2 + "_usu");

    wM.setGeometry(this->geometry());
    this->close();                  //Cierra Inicio de sesion/ registro
    wM.setVisible(true);            //Muestra ventana de elección de modo de juego

}

void VentanaLogin::on_actionNombresValidos_triggered()
{
    //Nombres de usuario válidos.
    msgBox.setText("Names cannot contain spaces or any of the following characters:\n |/<>*?*:\"\\");
    msgBox.exec();
}

void VentanaLogin::on_actionClavesValidas_triggered()
{
    //Contraseñas válidas.
    msgBox.setText("All passwords are valid except those containing spaces");
    msgBox.exec();
}
