#ifndef JUEGO_H
#define JUEGO_H

/*
 * Clase usada para el manejo de los elementos del juego.
    Nota sobre la diferencia entre localización y nivel:
    localización se refiere a todos los puntos del juego, ya sea la historia, el nivel o los puntajes finales.
    Nivel se refiere únicamente a la sección donde el usuario interactúa mediante el manejo de los personajes con el programa.
*/

#include <QGraphicsRectItem>
#include "animacion.h"
#include "aliado.h"
#include "meteorito.h"
#include "plataforma.h"
#include "moneda.h"
#include "enemigo.h"
#include "bala.h"
#include "escritor.h"

extern infoArchivo infoUsuario;
extern QVector<infoArchivo> informacionJuego;

class Juego: public QObject
{
    Q_OBJECT
private:
    //Manejo de items de texto mostrados al usuario
    QString TimeAsSting();
    void ActualizarCountdown();
    void actualizarDisparos();
    void evaluarNivel();

public:
    Juego(QObject *parent=nullptr);

    void actualizar(); //Actualización de los objetos del juego.
    //Métodos que añaden objetos al juego.
    void Trackers();
    void DisparosEnemigos();
    void DisminuirVidas();
    void AumentarPuntaje();
    void NuevosPuntos();
    void NuevosObstaculos();
    void ActualizarPuntos();
    //Métodos para la conexión de niveles.
    void ReiniciarNivel();
    void CambiarLocalizacion();
    int getNivel();
    bool getModoJuego() { return multijugador; }
    QVector<Plataforma *> getPlataformas() { return plataformas; }

private:
    Puntaje *p;
    Animacion *A = new Animacion; //También se crea método get
    bool estado;
    unsigned short int vidas = 1;
    unsigned long int contTime = 0, duracion = 3900;
    string nombreUsuario;
    QGraphicsTextItem *Score = new QGraphicsTextItem;   //Puntaje que se va llevando en el nivel
    QGraphicsTextItem *Lives1 = new QGraphicsTextItem;  //Vidas del personaje 1 en el nivel
    QGraphicsTextItem *Lives2 = new QGraphicsTextItem;  //Vidas del personaje 2 en el nivel
    QGraphicsTextItem *Time = new QGraphicsTextItem;    //Tiempo que le queda al usuario para completar el nivel

    QVector<Plataforma *> plataformas = {};
    int y_nE, cantidadMonedas = 1;

public:
    QTimer *timer;                                      //Crea el timer

    Animacion *getA() const;
    //Contenedores para almacenar los elementos del juego
    QVector<Aliado *> jugadores = {};
    QVector<Enemigo*> Enemigos = {};
    QList<Enemigo*> EnemEstaticos = {};
    QVector<Meteorito*> disparosEnemigos = {};
    QVector<Bala*> disparosAliados = {};
    QVector<Meteorito *> meteoritos = {};
    QVector<Moneda *> estrellas = {};
    int puntajeNivel = 0;
    bool estado_juego = false;                          //Determina si se leen las letras presionadas o no
    bool J_vivo[2]={true,false};
    bool multijugador = false;
    unsigned short int localizacion = 0;                //Historia/Juego
};

#endif // JUEGO_H


//~
