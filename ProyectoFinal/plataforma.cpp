#include "plataforma.h"

double Plataforma::getFrictionC() const
{
    return FrictionC;
}

Plataforma::Plataforma(double _ancho, double _alto, double x_inicial, double y_inicial, double Vx, double Vy,unsigned int max_avance, double friccion)
{
    maxAvance=max_avance;
    velX=Vx;
    velY=Vy;
    posX=x_inicial;
    posY=y_inicial;
    ancho=_ancho;
    alto=_alto;
    FrictionC=friccion;
    setPos(posX,posY);
}

void Plataforma::Mover()
{
    //Moviendo el cuerpo: se modificará la posición de manera uniforme mientras que contPos no
    //sobrepase el límite. Si lo supera se cambia la dirección de movimiento y contPos retorna
    //a su valor inicial (0).
    if(contPos<maxAvance){
        posX+=velX;
        posY+=velY;
        contPos++;
    }
    else{
        velX=-velX;
        velY=-velY;
        contPos=0;
    }
    setPos(posX,posY);

}

QRectF Plataforma::boundingRect() const
{
   return QRectF(posX,posY,ancho,alto);

}

void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::magenta);
    painter->drawRect(boundingRect());
}
