#ifndef ENEMIGO_H
#define ENEMIGO_H
/*
 Clase para crear los enemigos de cada nivel. Hereda de la clase cuerpo.
*/

#include <QGraphicsRectItem>
#include "cuerpo.h"
#include "meteorito.h"
#include "bala.h"

class Enemigo: public cuerpo, public QGraphicsPixmapItem //public QGraphicsRectItem
{
public:
    Enemigo(unsigned int tipo, unsigned short int tipo_b, unsigned short int life, int posX, int posY, int posX_arma, int posY_arma, int pos_inicialX, int pos_inicialY, float vel, float a, float theta_disparo, int radio_bala, float vel_bala);

    bool ActualizarPosicion();
    bool ColisionBala() override;
    void dibujarItem() override;
    void disparar() override;
    void actualizarVida();
    int getPosicion_x() const;
    int getPosicion_y() const;

public:
    bool vivo = true;

private:
    unsigned short int enemigo;
    unsigned short int disparo;
    unsigned short int vidas;
    int ancho = 60, alto = 60;
    int posicion_x, posicioninicial_x;
    int posicion_y, posicioninicial_y;
    int posicionX_arma;
    int posicionY_arma;
    int posX=0,posY=0;
    //Valores para los disparos:
    int radio_b;
    float aceleracion;
    float velocidad;
    float angulo_b;
    float velocidad_b;

    Meteorito *bala; //Disparo tipo meteorito.
    QPixmap apariencia;

};

#endif // ENEMIGO_H
