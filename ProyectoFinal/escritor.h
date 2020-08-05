#ifndef ESCRITOR_H
#define ESCRITOR_H
/*
 Clase usada para el manejo de archivos.
 Los archivos se encuentran organizados de la siguiente manera:
 -Archivos para cada usuario:
 <indicador>    NombreUsuario   puntajeAcumulado    localización
 <indicador>: puede ser multijugador (<M>) o individual (<I>)
 localización: va desde 0 a 6, aunque puede alterarse al 8 (caso especial no usado en esta clase)
 -USUARIOS.txt:
 NombreUsuario  contraseña  puntajeMayorMultijugador    puntajeMayorIndividual

 Estos archivos se encuentran dentro de la carpeta PARTIDAS
*/
#include <QList>
#include <QMessageBox>
#include "informacion.h"

using namespace std;

class Escritor
{
public:
    QVector<infoArchivo> leerArchivo(string nombre_archivo);
    void registrarUsuario(string name_ingresado, string password_ingresado);    //Registra un nuevo usuario al sistema
    void guardarPartida(QVector<infoArchivo> infoJuego);
    void actualizarInformacion(QVector<infoArchivo> infoNueva);
    void actualizarInfoLocal();
    void actualizarInfoGeneral();

private:
    QMessageBox msgBox;
    QVector<infoArchivo> NuevainformacionU = {};
};

#endif // ESCRITOR_H
