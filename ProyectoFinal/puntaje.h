#ifndef PUNTAJE_H
#define PUNTAJE_H
/*
 Clase que recolecta los puntajes del archivo USUARIOS.txt, los cuales corresponden al puntaje mayor que ha obtenido el usuario
 asociado a ese número. Adicionalmente, ordena los puntajes de mayor a menor mediante un algoritmo de fuerza bruta y procede
 a mostrar en pantalla, como máximo, los diez mejores puntajes.
 Es importante resaltar que los números que se van a sacar dependerán del modo de juego en el que está jugando el usuario.
*/
#include <QFont>
#include <QPainterPath>
#include <QBrush>

#include <iostream>
using namespace std;

#include "informacion.h"
#define INFINITO 40000000

class Puntaje
{
public:
    struct infoUsuario
    {
    /* "nombre" se refiere al nombre del usuario
     * y "puntaje" al puntaje del usuario en la
     * partida en curso.
    */
        string nombre;
        long int puntaje;
    };

    Puntaje();
    void calculoPuntajes();
    void calculoM_Puntajes();
    void dibujarPuntajes();

private:
    QFont font;
    QPainterPath contenido, path;
    int aux = -1;
    long int Maxi = INFINITO, Mini = -1;
    infoUsuario Persona, formatoPuntaje;
    QVector<infoArchivo> infoArchivoUsuarios = {};
    QVector<infoUsuario> TodosPuntajes = {};
    QVector<infoUsuario> MaxPuntajes = {};

private:
    QVector<int> Indicador ={};
    bool evaluarIndicador(int n);
    void ordenarPuntajes();
};

#endif // PUNTAJE_H
