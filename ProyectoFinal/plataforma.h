#ifndef PLATAFORMA_H
#define PLATAFORMA_H


#include<QObject>
#include<QGraphicsItem>
#include<QPainter>

class Plataforma: public QGraphicsItem
{
  /* Clase que se moverá con movimiento rectilíneo uniforme mientras recorre una cantidad
   * de posiciones definida por maxAvance para después cambiar la orientación de su velocidad
   * de manera que se mueva de manera uniforme en dirección contraria y con la misma
   * condición de cambio de velocidad que el caso anterior.
   * Cada plataforma tendrá un coeficiente de fricción con respecto a los personajes del juego
   * (será constante para todos los personajes).
   * Para que la plataforma se mueva de manera horizontal debe implementarse la clase con velY=0
   * y para que se mueva de manera vertical con Vx=0, de lo contrario se moverá con un ángulo.
   */
private:
    unsigned int contPos=0, maxAvance=0;
    double velX=0,velY=0, posX=0,posY=0,ancho=0,alto=0;
    double FrictionC=0;
    QPixmap apariencia;

public:
    Plataforma(double _ancho,double _alto,double x_inicial,double y_inicial,double Vx,double Vy,unsigned int max_avance,double friccion, unsigned short int tipo=1);

    double getFrictionC() const;
    void Mover();
    void ColisionBala();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getPosY();
    int getPosX();
    int getAncho() const;
    QRectF boundingRect() const;

};


#endif // PLATAFORMA_H
