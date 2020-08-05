#include "moneda.h"
#include "aliado.h"
#include "juego.h"
#include <QDebug> //

extern Juego *juego;

Moneda::Moneda(int _valor, double radio_moneda, double radio_giro,double x_inicial, double y_inicial, double _velAngular, unsigned short int tipo_, int _tiempo)
{
    valor=_valor;   //Cantidad de puntos que tendrá la moneda
    tipo = tipo_;
    radioMoneda=radio_moneda;
    radioGiro=radio_giro;
    posX=x_inicial;
    posY=y_inicial;
    Xinicial=x_inicial;
    Yinicial=y_inicial;
    velAngular=_velAngular;
    tiempo=_tiempo;
    if(tipo==1)
        apariencia = QPixmap(":/primera/Elementos juego/Star1.png");
    else if(tipo==2)
        apariencia = QPixmap(":/primera/Elementos juego/Star2.png");
    else if(tipo==3)
        apariencia = QPixmap(":/segunda/Elementos juego/Star3.png");
    Aparecer();
}

void Moneda::Aparecer()
{
    //Colocando moneda en su posición inicial
    setPos(posX,posY);
}

void Moneda::Mover()
{
    //Actualizando ángulo y posiciones de la moneda
    angulo+=velAngular;
    posX=Xinicial+radioGiro*cos(angulo);
    posY=Yinicial+radioGiro*sin(angulo);
    Aparecer();
}

QRectF Moneda::boundingRect() const
{
  return QRectF(-radioMoneda,-radioMoneda,2*radioMoneda,2*radioMoneda);

}

void Moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Dibujar moneda según el tipo y con tamaño definido por boundingRect().
    painter->drawPixmap(boundingRect(),apariencia,apariencia.rect());
}

int Moneda::getTiempo() const
{
    return tiempo;
}

void Moneda::setTiempo(int value)
{
    tiempo = value;
}

bool Moneda::getInScene() const
{
    return InScene;
}

void Moneda::setInScene(bool value)
{
    InScene = value;
}

void Moneda::AumentarPuntaje(unsigned int E, unsigned short int tipoaliado)
{
    /*
     * Método que determina si el aliado o su disparo colisiona con una moneda y aumenta el puntaje de nivel
     * del juego según el valor de la moneda.
     * Además, si la moneda es de tipo 0 (moneda de cambio de nivel en nivel 1) entonces se declara el nivel como superado.
     *
    */
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i]))==typeid(Aliado)){
            if(this->valor>0){
                juego->puntajeNivel += this->valor;
                this->hide();
                this->tiempo = 0;
                juego->estrellas.removeAt(E);
                scene()->removeItem(this);
            }
            else if(valor==0 && juego->getNivel()==1){ //Nivel superado...
                juego->jugadores.at(tipoaliado)->NivelSuperado = true;
            }
        }
        else if(typeid(*(colliding_items[i]))==typeid(Bala)){
            juego->puntajeNivel += this->valor;
            this->hide();
            this->tiempo = 0;
        }
    }
}


