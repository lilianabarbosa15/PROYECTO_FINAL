#ifndef CUERPO_H
#define CUERPO_H

/*
    Clase base para las clases enemigo y aliado.
*/
#include <QBrush>

class cuerpo
{

public:
    //Funciones virtuales puras:
    virtual void dibujarItem() = 0;
    virtual void disparar()=0;
    virtual bool ColisionBala() = 0;
};


#endif // CUERPO_H
