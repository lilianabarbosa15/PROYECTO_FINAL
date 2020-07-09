#ifndef PLATAFORMA_H
#define PLATAFORMA_H


#include<QGraphicsItem>
#include<QPainter>
class Plataforma: public QGraphicsItem
{
private:
    unsigned int contPos=0, maxAvance=0;
    double velX=0,velY=0,posX=0,posY=0,ancho=0,alto=0;
    double FrictionC=0;
public:
    Plataforma(double _ancho,double _alto,double x_inicial,double y_inicial,double Vx,double Vy,unsigned int max_avance,double friccion);
    void Mover();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    double getFrictionC() const;
};


#endif // PLATAFORMA_H
