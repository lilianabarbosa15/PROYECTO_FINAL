#include "meteorito.h"
#include "aliado.h"
#include "plataforma.h"
#include "juego.h"
#include <QDebug> //

extern Juego *juego;


Meteorito::Meteorito(unsigned int _tipo, double _radio, double X, double Y, double _V0, double _angulo, QObject *parent): QObject{parent}
{
    tipo=_tipo;
    radio=_radio;
    posX=X;
    posY=Y;
    angulo=_angulo; //Por default se tiene 3PI/2
    V0=_V0;
    if(tipo==0) //Meteorito que cae en el nivel 1
        apariencia = QPixmap(":/primera/Elementos juego/Meteorite.png");
    else if(tipo==1)  //Disparo de nave aliada en nivel 2
        apariencia = QPixmap(":/segunda/Elementos juego/DisparoNaveA.png");
    else if(tipo==2)    //Disparo de nave enemiga en el nivel 2
        apariencia = QPixmap(":/segunda/Elementos juego/DisparoNaveEnemiga.png");
    else if(tipo==3)    //Disparo aliado en el nivel 3
        apariencia = QPixmap(":/tercera/Elementos juego/DisparoAliado.png");
    else if(tipo==4)    //Disparo enemigo en el nivel 3
        apariencia = QPixmap(":/tercera/Elementos juego/DisparoEnemigo.png");
    else if(tipo==5)    //Disparo enemigo que rebota en el nivel 3
        apariencia = QPixmap(":/tercera/Elementos juego/Disparo_2_Enemigo.png");
    setPos(posX,posY);
}

QRectF Meteorito::boundingRect() const
{
     return QRectF(-radio,-radio,2*radio,2*radio);
}

void Meteorito::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),apariencia,apariencia.rect());
}

bool Meteorito::rebotar()
{
    if(contRebote<2){
        Vy=-Vy;
        V0=V0*coefRestitucion;
        angulo=atan2(Vy,Vx);
        ActualizarVelocidad();
        ActualizarPosicion();
        contRebote++;
    }
    else{
        return false; //Ya no rebota
    }
    return true; //Rebotó
}

void Meteorito::ActualizarPosicion()
{
    //Segun ecuaciones de MRUA
    posX+=Vx*delta;
    posY-=Vy*delta-0.5*a*delta*delta;   //Resta por sistema de coordenadas de la escena
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

void Meteorito::Desaparecer()
{
    //Remover cuerpo de escena en la que se creó.
    scene()->removeItem(this);
}


void Meteorito::setA(double value)
{
    a = value;
}

float Meteorito::getPosicionY()
{
    return posY;
}

float Meteorito::getPosicionX()
{
    return posX;
}

void Meteorito::setDelta(int value)
{
    delta = value;
}

double Meteorito::getCoefRestitucion() const
{
    return coefRestitucion;
}

bool Meteorito::Colision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if((typeid(*(colliding_items[i]))==typeid (Plataforma))){
            return true;
        }
    }
    return false;
}

bool Meteorito::Mover()
{
    if(Colision()==true){
        if(rebotar()==false)
            return true; //Hay que eliminarlo
    }
    else if(posY<420){
        ActualizarVelocidad();
        ActualizarPosicion();
    }
    else{
        return true; //Hay que eliminarlo
    }
    return false;
}
