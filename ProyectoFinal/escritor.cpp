#include "escritor.h"
#include <fstream>
#include <QIcon>

extern infoArchivo infoUsuario;

#include <QDebug>   //
#include "juego.h"
extern Juego *juego;

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
    //Método utilizado cuando el usuario es nuevo en el sistema.
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
                << "\t" << infoJuego.at(i).int2;    //Localización en la que se encuentra
    }
    fichero.close();                                             //Se cierra el archivo
}

void Escritor::actualizarInformacion(QVector<infoArchivo> infoNueva)
{
    ofstream fichero;                                                               //Abre el archivo en modo lectura
    fichero.open("../ProyectoFinal/PARTIDAS/USUARIOS.txt");
    if(!fichero.is_open()){                                                         //Comprueba que el archivo fue abierto exitosamente
        msgBox.setWindowTitle(" ");
        msgBox.setWindowIcon(QIcon(":/iconos/iconW_nave.png"));
        msgBox.setText("ERROR");
        msgBox.exec();
        exit(1);
    }
    for(unsigned short int i=0; i<infoNueva.size(); i++)
    {
        fichero << endl << infoNueva.at(i).string1  //Indica el nombre del usuario
                << "\t" << infoNueva.at(i).string2  //La contraseña del usuario
                << "\t" << infoNueva.at(i).int1     //Puntaje máximo en modo multijugador
                << "\t" << infoNueva.at(i).int2;    //Puntaje máximo en modo individual
    }
    fichero.close();                                             //Se cierra el archivo
}

void Escritor::actualizarInfoLocal()
{
    /*
      Método que asigna el localizador a la estructura asociada al usuario en el momento de iniciar una partida.
      Donde el indicador corresponde a <M> (multijugador) e <I> (individual).
      Posteriormente, se agregan a la información general del juego, que corresponde a un vector de la estructura
      que se modificó.
      El formato de guardado es el siguiente:
      <indicador>    nombreUsuario   puntajeAcumulado   localizador
    */
    if(juego->multijugador==true){
        infoUsuario.string1 = "<M>";
        informacionJuego.replace(0,infoUsuario);
    }
    else{
        infoUsuario.string1 = "<I>";
        informacionJuego.replace(1,infoUsuario);
    }
    Escritor().guardarPartida(informacionJuego);
}

void Escritor::actualizarInfoGeneral()
{
    /*Método que obtiene todos los nombres y contraseñas de los usuarios en el sistema, junto a sus máximos puntajes
    en cada modo de juego, además de alterar la información del usuario en curso (solamente se alteran los puntajes
    en cada modo de juego).
    */
    infoArchivo nuevaInfo = infoUsuario;
    NuevainformacionU = Escritor().leerArchivo("USUARIOS");  //Se pasan los datos de las contraseñas y los nombres a un vector
    infoUsuario = nuevaInfo;
    nuevaInfo = {};
    for(int i=0; i<NuevainformacionU.size(); i++){
        if( NuevainformacionU.at(i).string1 == infoUsuario.string2 ){
            nuevaInfo.string1 = NuevainformacionU.at(i).string1;        //Nombre del usuario
            nuevaInfo.string2 = NuevainformacionU.at(i).string2;        //Contraseña del usuario
            if(juego->multijugador==true){
                if( NuevainformacionU.at(i).int1 < infoUsuario.int1){
                    nuevaInfo.int1 = infoUsuario.int1;               //Nuevo mayor puntaje en modo multijugador
                    nuevaInfo.int2 = NuevainformacionU.at(i).int2;              //Puntaje en modo individual
                    NuevainformacionU.replace(i, nuevaInfo);
                    Escritor().actualizarInformacion(NuevainformacionU);
                }
            }else{
                if( NuevainformacionU.at(i).int2 < infoUsuario.int1){
                    nuevaInfo.int1 = NuevainformacionU.at(i).int1;              //Puntaje en modo individual
                    nuevaInfo.int2 = infoUsuario.int1;               //Nuevo mayor puntaje en modo multijugador
                    NuevainformacionU.replace(i, nuevaInfo);
                    Escritor().actualizarInformacion(NuevainformacionU);
                }
            }
            break;
        }
    }
}
