#include "animacion.h"

extern QGraphicsScene *escena;

#include "juego.h"
extern Juego *juego;


Animacion::Animacion(QObject *parent): QObject{parent}
{
}

bool Animacion::getActivado() const
{
    return activado;
}

void Animacion::setActivado(bool value)
{
    activado = value;
}

int Animacion::getNivel() const
{
    return nivel;
}

void Animacion::setNivel(int value)
{
    nivel = value;
}

void Animacion::AnimacionNivel1()
{
    //Método que controla animación de nivel 1
    if(progreso<Nivel1.size()){
        slide.load(Direccion+Nivel1.at(progreso));
        QPixmap scaled=slide.scaled(escalaW,escalaH);
        escena->addPixmap(scaled);
        progreso++;
    }
    else{
        escena->clear();
        activado=false;
        juego->CambiarLocalizacion();
    }
}

void Animacion::AnimacionNivel2()
{
    //método que muestra animación del nivel 2
    if(progreso<Nivel2.size()){
        slide.load(Direccion+Nivel2.at(progreso));
        QPixmap scaled=slide.scaled(escalaW,escalaH);
        escena->addPixmap(scaled);
        progreso++;
    }
    else{
        escena->clear();
        activado=false;
        juego->CambiarLocalizacion();
    }
}

void Animacion::AnimacionNivel3()
{
    //Método que muestra animación del nivel 3

    if(progreso<Nivel3.size()){
        //Condición para animación de cuerpos que se mueven por gravitación:
        if(Nivel3.at(progreso)=="cuerpos"){
            escena->setBackgroundBrush(Qt::black);
            escena->clear();

            uno= new CuerpoAnim(70,100,100,1,0);
            dos= new CuerpoAnim(70000,500,300,0,0);
            QPixmap Pixmap(":/simulacion/Simulacion del comic/planeta animacion.png");
            uno->setPixmap(Pixmap.scaled(QSize(10,10)));
            escena->addItem(uno);
            escena->addItem(dos);

            timer=new QTimer;
            connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
            timer->start(inicioTimer);

            progreso++;
        }
        else{
            if(progreso==5){
                escena->clear();
                timer->stop();
            }
            escena->setBackgroundBrush(Qt::lightGray);
            slide.load(Direccion+Nivel3.at(progreso));
            QPixmap scaled=slide.scaled(escalaW,escalaH);
            escena->addPixmap(scaled);
            progreso++;
        }
    }
    else{
        escena->clear();
        planetas.clear();
        activado=false;
        delete timer;
        juego->CambiarLocalizacion();
    }

}

void Animacion::AnimacionFinal()
{
    //Método que muestra animación del final.
    if(progreso<Final.size()){
        slide.load(Direccion+Final.at(progreso));
        QPixmap scaled=slide.scaled(escalaW,escalaH);
        escena->addPixmap(scaled);
        progreso++;
    }
    else{
        escena->clear();
        activado=false;
        juego->localizacion = 8;
        setActivado(false);
        juego->CambiarLocalizacion();
    }
}

void Animacion::Presentar()
{
    /*Método que determina qué animación presentar según el nivel actual del juego.
     * Nivel 0-> animación antes de nivel 1.
     * Nivel 2-> Animación antes de nivel 2
     * Nivel 4->Animación antes de nivel 3
     * Nivel 6->Animación final
     */
    if(nivel==0)
        AnimacionNivel1();
    else if(nivel==2)
        AnimacionNivel2();
    else if(nivel==4)
        AnimacionNivel3();
    else if(nivel==6)
        AnimacionFinal();
}

void Animacion::actualizar()
{
    //Slot que actualiza las posiciones de los cuerpos de la animación del nivel 3 según movimiento planetario.
    planetas.clear();
    planetas.push_back(uno);
    planetas.push_back(dos);
    uno->setPlanetas(planetas);
    dos->setPlanetas(planetas);
    uno->actualizar();
    dos->actualizar();
}

