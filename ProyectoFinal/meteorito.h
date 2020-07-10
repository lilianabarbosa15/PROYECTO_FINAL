#ifndef METEORITO_H
#define METEORITO_H


#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<math.h>
#include"plataforma.h"
class Meteorito: public QGraphicsItem
{
    /* Clase que se utilizara para los meteoritos del nivel 2 y los disparos del nivel3:
      El tipo 1 corresponde a los meteoritos y el tipo 2 corresponde a los disparos.
      El cuerpo se movera siguiendo las ecuaciones de movimiento rectilineo uniformemente
      acelerado.
      Para el caso de los meteoritos se desea que se muevan de manera rectilinea y desacelerada
      por lo que al implementar la clase no es necesario introducir el angulo inicial ya que
      por default se ha determinado el angulo de 3*PI/2 (radianes) que produce un movimiento
      rectilineo hacia abajo.
      Con el metodo setAceleracion puede variarse la aceleracion default de 9,8 (m/s2)
      a una aceleracion negativa para que el cuerpo desacelere al caer. Sin embargo es posible
      que este cambio de aceleracion cause comportamientos extraños como un periodo de movimiento
      hacia abajo y otro periodo hacia arriba por lo que se cambiara la velocidad a conveniencia.
      (Por probar: utilizar mejor friccion o resistencia del aire y no variar la aceleracion).
      Para el caso del meteorito se recomienda ingresar angulos que se encuentren en el rango
      [0,2PI] (radianes)para obtener un movimiento parabolico (Por probar: rebote del cuerpo al chocar
      con otros cuerpos)
    */
private:
    double posX=0, posY=0, V0=0, Vx=0,Vy=0;
    double angulo=0, radio=0;
    double a=9.8,delta=0.1; //delta: cambio en el tiempo (variar segun timer para mayor o
    //menor velocidad de la animacion)
    unsigned int tipo=0;
    unsigned int contRebote=0; //para implementacion de rebotes (por probar)

public:
    Meteorito(unsigned int _tipo, double _radio, double X, double Y, double _V0, double _angulo=(3*M_PI)/2 );
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void rebotar();
    void ActualizarPosicion();
    void ActualizarVelocidad();
    void Desaparecer(QGraphicsScene *Scene);
    void setA(double value);
};


#endif // METEORITO_H
