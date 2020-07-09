#include "ventanalogin.h"
#include "ui_ventanalogin.h"
#include <fstream>

#include <QDebug> //

VentanaLogin::VentanaLogin(QWidget *parent) : QMainWindow(parent), ui(new Ui::VentanaLogin){
    ui->setupUi(this);
    msgBox.setWindowTitle(" ");
    msgBox.setWindowIcon(QIcon(":/iconW_nave.png"));
}

VentanaLogin::~VentanaLogin() { delete ui; }

void VentanaLogin::on_nuevoUsuario_clicked()
{
    name_ingresado = (ui->name->text()).toStdString();
    password_ingresado = (ui->password->text()).toStdString();
    if(verificarDato()==true){
        leerArchivo();                                  //Buscar en el archivo los datos ingresados
        if(estadoName ==false){                         //El nombre no se encontró
            registrarUsuario();
            cambiarVentana();
        }
        else{
            msgBox.setText("EL USUARIO YA EXISTE     ");
            msgBox.exec();
        }
    }
    else{
        msgBox.setText("DATOS ERRONEOS     ");
        msgBox.exec();
    }
}

void VentanaLogin::on_existeUsuario_clicked()
{
    name_ingresado = (ui->name->text()).toStdString();
    password_ingresado = (ui->password->text()).toStdString();
    if(name_ingresado!="" && password_ingresado!=""){
        leerArchivo();                                      //Buscar en el archivo los datos ingresados
        if(estadoName==false || estadoPassword==false){     //El nombre no se encontró
            msgBox.setText("LA CUENTA O LA CONTRASEÑA ES INCORRECTA");
            msgBox.exec();
        }
        else
            cambiarVentana();
    }
    else{
        msgBox.setText("SE DEBEN COMPLETAR LOS ESPACIOS");
        msgBox.exec();
    }
}

bool VentanaLogin::verificarDato()
{
    if(password_ingresado!="" && name_ingresado!=""){
        //Verifica nombre
        for(unsigned short int v=0; v< sizeof(v_evaluar); v++){
            for(unsigned int n=0; n<name_ingresado.size(); n++){
                if(*(v_evaluar+v) == name_ingresado.at(n))
                    return false;                                   //Uno de los caracteres del nombre ingresado no es valido
            }
        }
        //Verifica contraseña
        for(unsigned int c=0; c<password_ingresado.size(); c++){
            if(password_ingresado.at(c)==' ')
                return false;                                       //La contraseña contiene espacios
        }
    }else
        return false;                                               //No se ingresaron datos
    return true;                                                    //Nombre correcto
}

void VentanaLogin::leerArchivo()
{
    estadoName = false;                 //Supone que el nombre NO está guardado
    estadoPassword = false;             //Supone que la contraseña NO está guardada
    ifstream fichero;                                           //Abre el archivo en modo lectura
    fichero.open("../ProyectoFinal/PARTIDAS/USUARIOS.txt");         //USUARIOS.txt almacena el nombre y la contraseña de los usuarios
    if(!fichero.is_open()){                                     //Comprueba que el archivo fue abierto exitosamente
        msgBox.setText("ERROR");
        msgBox.exec();
        exit(1);
    }
    while(!fichero.eof()){                                       //Itera mientras que no se haya llegado al final del archivo
        fichero >> name_fichero;
        fichero >> password_fichero;
        if(name_ingresado == name_fichero){
            estadoName = true;
            if (password_ingresado == password_fichero)
                estadoPassword = true;
            break;
        }
    }
    fichero.close();                                             //Se cierra el archivo
}

void VentanaLogin::registrarUsuario()
{
    //Guarda los datos ingresados en el archivo predeterminado de usuarios
    ofstream fichero;
    fichero.open("../ProyectoFinal/PARTIDAS/USUARIOS.txt",ios::app);
    fichero << endl << name_ingresado << "\t" << password_ingresado;
    fichero.close();
    //Genera un archivo nuevo para el usuario
    ofstream streamEscritura("../ProyectoFinal/PARTIDAS/"+name_ingresado+"_usu.txt");
    streamEscritura.close();
}

void VentanaLogin::cambiarVentana()
{
    this->close();                  //Cierra Inicio de sesion/ registro
    wM.show();                      //Muestra ventana de elección de modo de juego
}

void VentanaLogin::on_actionNombresValidos_triggered()
{
    msgBox.setText("Los nombres no pueden contener espacios o alguno de los siguientes caracteres:\n |/<>*?*:\"\\");
    msgBox.exec();
}

void VentanaLogin::on_actionClavesValidas_triggered()
{
    msgBox.setText("Todas las contraseñas son validas excepto las que contienen espacios");
    msgBox.exec();
}
