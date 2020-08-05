#include "puntaje.h"
#include "escritor.h"

#include <QGraphicsScene>
#include <QDebug>

extern QGraphicsScene *escena;

#include "juego.h"
extern Juego *juego;

Puntaje::Puntaje()
{
    calculoPuntajes();
    calculoM_Puntajes();
}

void Puntaje::calculoPuntajes()
{
    //Método que obtiene y almacena todos los puntajes de los usuarios.
    infoArchivoUsuarios = Escritor().leerArchivo("USUARIOS");
    for(unsigned int i=0; i<(unsigned)infoArchivoUsuarios.size(); i++){
        formatoPuntaje.nombre = infoArchivoUsuarios.at(i).string1;
        if(juego->multijugador==true) // <M>
            formatoPuntaje.puntaje = infoArchivoUsuarios.at(i).int1;
        else
            formatoPuntaje.puntaje = infoArchivoUsuarios.at(i).int2;
        TodosPuntajes.push_back(formatoPuntaje);
    }
}

void Puntaje::calculoM_Puntajes()
{
    ordenarPuntajes();
    dibujarPuntajes();
}

bool Puntaje::evaluarIndicador(int n)
{
    for(unsigned int c=0; c<(unsigned)Indicador.size(); c++){
        if(n==Indicador.at(c))
            return true;        //El indicador se encuentra en el vector
    }
    return false;               //El indicador no está en el vector
}



void Puntaje::ordenarPuntajes()
{
    //Función que devuelve un contenedor con valores de mayor a menor
    MaxPuntajes.clear();
    for(unsigned int i=0; i<(unsigned)TodosPuntajes.size(); i++){
        for(unsigned int j=0; j<(unsigned)TodosPuntajes.size(); j++){
            if((TodosPuntajes.at(j).puntaje)>=Mini && evaluarIndicador(j)==false){
                if((TodosPuntajes.at(j).puntaje)<=Maxi){
                    Mini = TodosPuntajes.at(j).puntaje;
                    aux = j;
                }
            }
        }
        Maxi = Mini;
        Mini = -1;
        Indicador.push_back(aux);
        if(Indicador.size()>10)
            break;
        else{
            Persona.nombre = TodosPuntajes.at(aux).nombre;
            Persona.puntaje = TodosPuntajes.at(aux).puntaje;
            MaxPuntajes.push_back(Persona);
        }
    }
}

void Puntaje::dibujarPuntajes()
{
    //Método que imprime los puntajes en la escena.
    font.setPixelSize(35);
    font.setBold(false);
    font.setFamily("Calibri");
    if(juego->multijugador)
        path.addText(45, 50, font,  "THE BEST SCORES AT MULTIPLAYER MODE");
    else
        path.addText(30, 50, font,  "THE BEST SCORES AT SINGLE PLAYER MODE");
    escena->addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::white));

    font.setPixelSize(20);
    for(unsigned short int n=0; n<(unsigned)MaxPuntajes.size(); n++){   // + MaxPuntajes.at(n).puntaje
        contenido.addText(60, 90 + n*30, font, QString::fromStdString(to_string(n+1)) +
                                               ")    " +
                                               QString::fromStdString(MaxPuntajes.at(n).nombre) +
                                               "   ..............  " +
                                               QString::fromStdString(to_string(MaxPuntajes.at(n).puntaje)));
    }
    escena->addPath(contenido, QPen(QBrush(Qt::white), 1), QBrush(Qt::white));
}
