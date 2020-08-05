#ifndef MONEDA_H
#define MONEDA_H

#include<math.h>
#include<QGraphicsItem>
#include<QPainter>
#include <QMediaPlayer>
class Moneda: public QGraphicsItem
{
    /*Esta clase moneda se moverá con movimiento circular uniforme definido por una
     circunferencia con radio establecido por radioGiro.
     El origen del sistema de coordenadas de este movimiento se encuentra en el centro
     de esta circunferencia y las coordenadas para el movimiento circular son:
     X=radioGiro*cos(angulo)
     Y=radioGiro*sen(angulo)
     siendo angulo el ángulo (en radianes) con respecto al eje X del sistema de coordenadas
     definido anteriormente.
     Para el movimiento de la moneda se actualiza angulo según una velocidad angular (en radianes/s)
     que se recomienda definir entre el intervalo (0,2*pi) (intervalo abierto).
     Si la velocidad angular se define positiva, entonces la moneda girará en sentido horario
     de lo contrario girará el sentido antihorario.
    */
private:
    int valor=0, tiempo=0;
    bool InScene=true;
    double posX=0,posY=0,radioGiro=0,radioMoneda=0; //posición de la moneda, radio de giro y radio de la moneda
    double velAngular=0, angulo=0,Xinicial=0,Yinicial=0;
    unsigned short int tipo;
    QPixmap apariencia;

public:
    Moneda(int _valor, double radio_moneda, double radio_giro,double x_inicial, double y_inicial, double _velAngular, unsigned short int tipo_=1, int _tiempo=0);

    int getTiempo() const;
    bool getInScene() const;
    void Aparecer();
    void Mover();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void setTiempo(int value);
    void setInScene(bool value);
    void AumentarPuntaje(unsigned int E=0, unsigned short int tipoaliado=0);
    unsigned int getValor(){return valor;}
    QRectF boundingRect() const;
};

#endif // MONEDA_H
