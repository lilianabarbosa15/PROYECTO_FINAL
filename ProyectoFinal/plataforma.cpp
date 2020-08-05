#include "plataforma.h"
#include <QDebug>
#include <QGraphicsScene>
#include "bala.h"


Plataforma::Plataforma(double _ancho, double _alto, double x_inicial, double y_inicial, double Vx, double Vy, unsigned int max_avance, double friccion, unsigned short int tipo)
{
    maxAvance=max_avance;
    velX=Vx;
    velY=Vy;
    posX=x_inicial;
    posY=y_inicial;
    ancho=_ancho;
    alto=_alto;
    FrictionC=friccion;
    if(tipo!=1)
        apariencia = QPixmap(":/primera/Elementos juego/Platform.png").scaled(ancho,alto);
    else
        apariencia = QPixmap(":/tercera/Elementos juego/Platform3.png").scaled(ancho,alto); //La otra apariencia de la plataforma
    setPos(posX*0.0001,posY*0.0001);
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
    setPos(posX*0.0001,posY*0.0001);
}

QRectF Plataforma::boundingRect() const
{
    return QRectF(posX,posY,ancho,alto);
}

void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posX,posY,apariencia,1,1,posX*0.0001,posY*0.0001);
    ColisionBala();
}

double Plataforma::getFrictionC() const
{
    return FrictionC;
}

int Plataforma::getAncho() const
{
    return ancho;
}

void Plataforma::ColisionBala()
{
    QList<QGraphicsItem*>Colision=collidingItems();
    for(int i=0; i<Colision.size();i++){
        if(typeid(*Colision.at(i))==typeid(Bala)){
            scene()->removeItem(Colision.at(i));
        }
    }
}

int Plataforma::getPosX()
{
    return posX;
}

int Plataforma::getPosY()
{
    return posY;
}
