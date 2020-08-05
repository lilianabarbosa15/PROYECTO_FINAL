#ifndef METEORITO_H
#define METEORITO_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPainter>
#include<QGraphicsScene>
#include<math.h>
#include<QTimer>

class Meteorito: public QObject, public QGraphicsItem
{
    /* Clase que se utilizará para los disparos en el juego.
      El cuerpo se movera siguiendo las ecuaciones de movimiento parabólico.
      Para el caso de los meteoritos se desea que se muevan de manera rectilinea y desacelerada
      por lo que al implementar la clase no es necesario introducir el angulo inicial ya que
      por default se ha determinado el angulo de 3*PI/2 (radianes) que produce un movimiento
      rectilineo hacia abajo.
      Con el metodo setAceleracion puede variarse la aceleracion default de 9,8 (m/s2)
      a una aceleracion negativa para que el cuerpo desacelere al caer. Sin embargo es posible
      que este cambio de aceleracion cause comportamientos extraños como un periodo de movimiento
      hacia abajo y otro periodo hacia arriba por lo que se debe cambiar la velocidad a conveniencia.

      Para el caso del meteorito se recomienda ingresar angulos que se encuentren en el rango
      [0,2PI] (radianes)para obtener un movimiento parabolico.

      Para el tipo de meteorito que rebota se debe variar el coeficiente de restitución para variar la altura
      de los rebotes. En el caso del nivel 3 el coeficiente es menor a 1 para que se observe una pérdida de energía.
    */
    Q_OBJECT
private:
    double posX=0, posY=0, V0=0, Vx=0,Vy=0;
    double angulo=0, radio=0;
    double a=9.8,delta=0.1;      //delta: cambio en el tiempo (variar segun timer para mayor o
                                 //menor velocidad de la animacion)
    double coefRestitucion=0.65;
    unsigned int contRebote=0;      //para implementacion de rebotes
    unsigned int tipo=0;
    QTimer *timer= new QTimer;
    QPixmap apariencia;

public:
    Meteorito(unsigned int _tipo, double _radio, double X, double Y, double _V0, double _angulo=(3*M_PI)/2, QObject *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void ActualizarPosicion();
    void ActualizarVelocidad();
    void Desaparecer();
    void setA(double value);
    void setDelta(int value);
    void Colisiones();
    bool Mover();
    bool Colision();
    bool rebotar();
    float getPosicionY();
    float getPosicionX();
    double getCoefRestitucion() const;

};

#endif // METEORITO_H
