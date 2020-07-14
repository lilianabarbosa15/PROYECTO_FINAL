#include "meteorito.h"


Meteorito::Meteorito(unsigned int _tipo, double _radio, double X, double Y, double _V0, double _angulo)
{
    tipo=_tipo;
    radio=_radio;
    posX=X;
    posY=Y;
    angulo=_angulo; //Por default se tiene 3PI/2
    V0=_V0;
    setPos(posX,posY);
}

QRectF Meteorito::boundingRect() const
{
     return QRectF(-radio,-radio,2*radio,2*radio);
}

void Meteorito::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Tipo 1: meteorito, Tipo 2:disparo
    if(tipo==1){
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect());
    }
    else if(tipo==2){
        painter->setBrush(Qt::cyan);
        painter->drawEllipse(boundingRect());
    }
}

void Meteorito::rebotar()
{
    //Posible metodo para rebote
    Vy=-Vy;
}

void Meteorito::ActualizarPosicion()
{
    //Segun ecuaciones de MRUA
    posX+=Vx*delta;
    posY-=Vy*delta-0.5*a*delta*delta; //Resta por sistema de coordenadas de la escena
    //(Si al implementarlo se genera una parabola que abre hacia arriba entonces cambiar
    //por +=)
    setPos(posX,posY);
}

void Meteorito::ActualizarVelocidad()
{
    //Segun ecuaciones de lanzamiento de proyectiles.
    Vx=V0*cos(angulo);
    Vy=V0*sin(angulo)-a*delta;
    V0=sqrt(Vy*Vy+Vx*Vx);
    angulo=atan2(Vy,Vx);
}

void Meteorito::Desaparecer(QGraphicsScene *Scene)
{
    //Remover cuerpo de escena ingresada.
    Scene->removeItem(this);
}


void Meteorito::setA(double value)
{
    a = value;
}
