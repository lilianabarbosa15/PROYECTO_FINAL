#ifndef ESCRITOR_H
#define ESCRITOR_H

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

private:
    QMessageBox msgBox;
};

#endif // ESCRITOR_H
