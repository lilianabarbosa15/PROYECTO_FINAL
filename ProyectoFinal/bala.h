#ifndef BALA_H
#define BALA_H
/*
 * Clase para creación de los disparos del jugador. Hereda de la clase meteorito y utiliza sus métodos  y atributos únicamente.
*/
#include "meteorito.h"

class Bala: public Meteorito
{
    using Meteorito::Meteorito;
};

#endif // BALA_H
