#ifndef ALIADO_H
#define ALIADO_H

//Clase para creación de los jugadores de todos los niveles. Hereda, junto con enemigo, de la clase cuerpo.

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QTimer>
#include <math.h>
#include "cuerpo.h"
#include "bala.h"
#include "meteorito.h"

#define Gravedad 9.8
#define paso 10
#define V 2600


class Aliado: public cuerpo, public QGraphicsPixmapItem
{
public:
    Aliado(int x, unsigned short int life);

    bool ColisionBala() override;
    void dibujarItem() override;
    void disparar() override;
    void actualizarVida(unsigned short int tipoaliado);
    void calcularmovimiento(int evento);
    void moverX(int evento);
    void moverY(unsigned short int tipo=1); //Predeterminadamente salta //SOLO SE USA EN EL NIVEL 1
    void actualizarcoordenadas(int posY_barra);
    void moverArma(float posibleangulo, int direccion);
    void verificarMovimiento();
    void verificarChoques(unsigned short int tipo=1);

public:
    unsigned short int vidas = 0;
    bool saltando = false, colision_barra = false;
    bool NivelSuperado = false;
    bool vivo = true;
    int posinicialY_barra = 400, posinicialX_barra = 0;

private:
    unsigned short int jugador;
    unsigned short int friccion = 0;
    unsigned int barra=0;
    short int ancho = 25, alto = 40;
    short int pixX_G = 41, pixY_G = 0;
    short int pixX = 0, pixY = 0;
    float Vy, velocidad = V;
    float tiempo = 0.4;
    float theta = M_PI/180.0;
    float angulo_disparo = 90.0*(M_PI/180.0);
    int posicion_x = 0, posicion_y = 360;
    int posicioninicial_x = 0, posicioninicial_y = 360;
    int posicionx_bala = posicion_x+(ancho/2);
    int posiciony_bala = posicion_y;
    int posicion_arma [8][2] = {}; //Posiciones de izquierda a derecha
    int indica_posicion_arma = 4;
    QPixmap aparienciaR, aparienciaL;
    QPixmap aparienciaG;
    Bala *bala;

};


#endif // ALIADO_H
