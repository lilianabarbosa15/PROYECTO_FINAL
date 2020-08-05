#include "enemigo.h"
#include "juego.h"
#include <QDebug>

extern Juego *juego;

Enemigo::Enemigo(unsigned int tipo, unsigned short int tipo_b, unsigned short life, int posX, int posY, int posX_arma, int posY_arma, int pos_inicialX, int pos_inicialY, float vel, float a, float theta_disparo, int radio_bala, float vel_bala)
{
    /*
     * Constructor que obtiene el tipo de enemigo con sus valores iniciales de vidas y posiciones, así como parámetros
     * para el disparo.
    */
    enemigo = tipo;
    disparo = tipo_b;
    vidas = life;
    posicion_x = posicioninicial_x = posX;
    posicion_y = posicioninicial_y = posY;
    posicionX_arma = posX_arma;
    posicionY_arma = posY_arma;
    velocidad =  vel;
    aceleracion = a;
    angulo_b = theta_disparo;
    radio_b = radio_bala;
    velocidad_b = vel_bala;
    dibujarItem();
    setPos(posicion_x, posicion_y);
}

void Enemigo::dibujarItem()
{
    /*
     Método que dibuja el enemigo según sea su tipo:
     1->enemigo nivel 2.
     2 y 3-> enemigos en plataformas del nivel 3.
     4 y 5-> enemigos que caen en el nivel 3.
    */
    if(enemigo==1){    //Naves
        apariencia = QPixmap(":/Enemigo/Elementos juego/SpaceshipE.png").scaled(ancho,alto);
    }
    else if(enemigo==2){
        alto = 40;
        apariencia = QPixmap(":/Enemigo/Elementos juego/Alien_G_R.png").scaled(ancho,alto);
    }
    else if(enemigo==3){
        alto = 40;
        apariencia = QPixmap(":/Enemigo/Elementos juego/Alien_G_L.png").scaled(ancho,alto);
    }
    else if(enemigo==4){
        alto = 40;
        apariencia = QPixmap(":/Enemigo/Elementos juego/Alien_G_DR.png").scaled(ancho,alto);
    }
    else if(enemigo==5){
        alto = 40;
        apariencia = QPixmap(":/Enemigo/Elementos juego/Alien_G_DL.png").scaled(ancho,alto);
    }
    setPixmap(apariencia.copy(posX,posY,ancho,alto));
}

void Enemigo::disparar()
{
    /*
     Método para realizar el disparo. Según el tipo de enemigo se decide el tipo de meteorito a disparar.
     Se modifica el valor de la aceleración según sea necesario para el movimiento del meteorito en el nivel.
    */
    if(enemigo==1)
        bala = new Meteorito(2,radio_b,posicionX_arma,posicionY_arma,velocidad_b, angulo_b);
    else if(enemigo==2 || enemigo==3)
        bala = new Meteorito(4, radio_b,posicionX_arma,posicionY_arma,velocidad_b, angulo_b);
    else if(enemigo==4)
        bala = new Meteorito(5, radio_b,posicionX_arma+10,posicionY_arma,velocidad_b, angulo_b);
    else if(enemigo==5)
        bala = new Meteorito(5, radio_b,posicionX_arma-10,posicionY_arma,velocidad_b, angulo_b);

    juego->disparosEnemigos.push_back(bala);
    bala->setA(15);
    bala->setFlag(QGraphicsItem::ItemIsFocusable);
    scene()->items().push_back(bala);
    scene()->addItem(bala);
}

bool Enemigo::ActualizarPosicion() //NIVEL 3
{
    /*
     Método para modificar la posición en Y de los enemigos que caen en el nivel 3.
     Esto se realiza según las ecuaciones de movimiento rectilíneo uniformemente acelerado.
     Retorna true si el enemigo ha llegado a la parte inferior de la escena y false en caso contrario.
    */
    if(posicion_y<400){
        posicion_y+=velocidad+(aceleracion/2);
        posicionY_arma=posicion_y+alto;
        setPos(posicion_x,posicion_y);
        return false;
    }
    else
        return true;
}

bool Enemigo::ColisionBala()
{
    /*
     Método que verifica si el enemigo ha chocado con una bala lanzada por el jugador.
     De ser así retorna true y de lo contrario retorna false.
     Adicionalmente, se elimina la bala de la escena antes de retornar true.
    */
    QList<QGraphicsItem*>Colision=collidingItems();
    for(int i=0; i<Colision.size();i++){
        if(typeid(*Colision.at(i))==typeid(Bala)){
            scene()->removeItem(Colision.at(i));
            return true;
        }
    }
    return false;
}

void Enemigo::actualizarVida()
{
    /*
     Método que verifica si el enemigo se mantiene con vida.
     Si este ha colisionado con una bala pero aún tiene vidas entonces estas se disminuyen.
     Si ya no se tiene vidas entonces se aumenta el puntaje del nivel en 10 puntos y se elimina de la escena.
    */
    if(vidas==0){
        this->hide();
        if(vivo==true){
            juego->puntajeNivel+=10;
            this->vivo = false;
        }
    }
    else if(vidas>0 && ColisionBala()==true){
        vidas--;
    }
}

int Enemigo::getPosicion_x() const
{
    return posicion_x;
}

int Enemigo::getPosicion_y() const
{
    return posicion_y;
}
