#include "escritor.h"
#include <fstream>
#include <QIcon>

extern infoArchivo infoUsuario;

#include <QDebug>   //

QVector<infoArchivo> Escritor::leerArchivo(string nombre_archivo)
{
    QVector<infoArchivo> infoLista = {};
    ifstream fichero;                                                     //Abre el archivo en modo lectura
    fichero.open("../ProyectoFinal/PARTIDAS/"+nombre_archivo+".txt");     //USUARIOS.txt almacena el nombre y la contraseña de los usuarios
    if(!fichero.is_open()){                                     //Comprueba que el archivo fue abierto exitosamente
        msgBox.setWindowTitle(" ");
        msgBox.setWindowIcon(QIcon(":/iconos/iconW_nave.png"));
        msgBox.setText("ERROR");
        msgBox.exec();
        exit(1);
    }
    while(!fichero.eof()){                                       //Itera mientras que no se haya llegado al final del archivo
        fichero >> infoUsuario.string1;
        fichero >> infoUsuario.string2;
        fichero >> infoUsuario.int1;
        fichero >> infoUsuario.int2;
        infoLista.append(infoUsuario);
    }
    fichero.close();                                             //Se cierra el archivo
    return infoLista;
}

void Escritor::registrarUsuario(string name_ingresado, string password_ingresado)
{
    //Guarda los datos ingresados en el archivo predeterminado de usuarios
    ofstream fichero;
    fichero.open("../ProyectoFinal/PARTIDAS/USUARIOS.txt",ios::app);
    fichero << endl << name_ingresado << "\t" << password_ingresado << "\t" << 0 << "\t" << 0;
    fichero.close();

    //Genera un archivo nuevo para el usuario
    ofstream streamEscritura("../ProyectoFinal/PARTIDAS/"+name_ingresado+"_usu.txt");
    streamEscritura << endl << "<M>" << "\t" << name_ingresado << "\t" << 0 << "\t" << 0;
    streamEscritura << endl << "<I>" << "\t" << name_ingresado << "\t" << 0 << "\t" << 0;
    streamEscritura.close();
}

void Escritor::guardarPartida(QVector<infoArchivo> infoJuego)
{
    ofstream fichero;                                                               //Abre el archivo en modo lectura
    fichero.open("../ProyectoFinal/PARTIDAS/"+infoJuego.at(0).string2+"_usu.txt");
    if(!fichero.is_open()){                                                         //Comprueba que el archivo fue abierto exitosamente
        msgBox.setWindowTitle(" ");
        msgBox.setWindowIcon(QIcon(":/iconos/iconW_nave.png"));
        msgBox.setText("ERROR");
        msgBox.exec();
        exit(1);
    }
    for(unsigned short int i=0; i<infoJuego.size(); i++)
    {
        fichero << endl << infoJuego.at(i).string1  //Indica el modo de juego
                << "\t" << infoJuego.at(i).string2  //Nombre del usuario
                << "\t" << infoJuego.at(i).int1     //Puntaje de la partida en curso
                << "\t" << infoJuego.at(i).int2;    //Nivel en el que se encuentra
    }
    fichero.close();                                             //Se cierra el archivo
}
