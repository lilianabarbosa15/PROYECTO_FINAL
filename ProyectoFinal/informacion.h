#ifndef INFORMACION_H
#define INFORMACION_H

#include <iostream>
using namespace std;

struct infoArchivo
{
/*
 * Estructura que maneja la información de los archivos de cada usuario y
 * la de los usuarios en el sistema.
 * Cuando se trata de la información del archivo de cada usuario, las variables corresponden a:
 *      --> string1 == indicador (<M> multijugador o <I> individual)
 *      --> string2 == nombre del usuario
 *      --> int1 == puntaje que se lleva hasta el momento
 *      --> int2 == la última localización en la que estuvo
 * Cuando se trata de la información del archivo con todos los usuarios del sistema, las variables corresponden a:
 *      --> string1 == nombre del usuario
 *      --> string2 == contraseña del usuario
 *      --> int1 == máximo puntaje en modo <M>
 *      --> int2 == máximo puntaje en modo <I>
*/
    string string1;
    string string2;
    unsigned long int int1; //unsigned int int1;
    unsigned long int int2; //unsigned short int int2;
};

#endif // INFORMACION_H
