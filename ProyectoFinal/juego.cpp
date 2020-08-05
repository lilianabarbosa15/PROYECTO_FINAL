#include "juego.h"
#include <QDebug> //

extern QGraphicsScene *escena;
extern Juego *juego;

Juego::Juego(QObject *parent): QObject{parent}
{
    //Obtener datos de la partida guardada:
    nombreUsuario = infoUsuario.string2;
    localizacion = infoUsuario.int2;

    if(infoUsuario.string1=="<M>") multijugador=J_vivo[1]=true;
    else multijugador=false;

    if(localizacion==1){            //............................Nivel 1 (Agregando elementos iniciales)
        A->setActivado(false); //Desactivando animación
        escena->setBackgroundBrush(QBrush(QImage(":/primera/Elementos juego/Spaceport_.jpg").scaled(680,400)));
        vidas=5;
        if(multijugador==true){
            cantidadMonedas = 80;
        }else
            cantidadMonedas = 50;
        plataformas.push_back(new Plataforma(680,1,0,400,0,0,0,0,0));           //Plataforma del suelo que no se ve
        escena->addItem(plataformas.back());
        plataformas.push_back(new Plataforma(80,10,60,335,0,-0.5,320,7,0));     //Plataforma que se mueve constantemente
        plataformas.at(1)->setFlag(QGraphicsItem::ItemIsFocusable);
        escena->addItem(plataformas.back());
        for(unsigned int n=210; n<=510; n+=150){
            plataformas.push_back(new Plataforma(80,10,n,335,0,0,0,5,0));
            escena->addItem(plataformas.back());
            plataformas.push_back(new Plataforma(90,10,n-25,180,0,0,0,5,0));
            escena->addItem(plataformas.back());
        }
    }else if(localizacion==3){      //............................Nivel 2(Elementos iniciales)
        A->setActivado(false); //Desactivando animación.
        vidas = 5;
        escena->setBackgroundBrush(QBrush(QImage(":/segunda/Elementos juego/Space.jpg").scaled(680,400)));
        y_nE = 10;
        if(multijugador==true){
            cantidadMonedas = 60;
        }else
            cantidadMonedas = 30;
        for(unsigned int c=100; c<501; c+=100){                                 //Se crean los enemigos
            EnemEstaticos.push_back( new Enemigo(1,2,15,c,y_nE,c+30,60,0,0,0,0,0,10,0));
            escena->addItem(EnemEstaticos.back());
        }
    }else if(localizacion==5){      //............................Nivel 3(Elementos iniciales)
        A->setActivado(false);
        vidas = 2;
        escena->setBackgroundBrush(QBrush(QImage(":/tercera/Elementos juego/Newplanet.jpg").scaled(680,400)));
        plataformas.push_back(new Plataforma(60,15,0,150,0,0,0,0));
        escena->addItem(plataformas.back());
        plataformas.push_back(new Plataforma(60,15,620,150,0,0,0,0));
        escena->addItem(plataformas.back());
        EnemEstaticos.push_back(new Enemigo(2,1,37,0,110,60,143,0,0,20,0,7*M_PI/4,5,100));
        escena->addItem(EnemEstaticos.back());
        EnemEstaticos.push_back(new Enemigo(3,1,37,620,110,600,143,0,0,0,0,5*M_PI/4,5, 100));
        escena->addItem(EnemEstaticos.back());
        escena->addItem(new Plataforma(680,10,0,400,0,0,0,0));     //Plataforma del suelo que no se ve
    }else{                          //............................Animación
        A->setActivado(true);                                       //Para que se pasen las diapositivas
        A->setNivel(localizacion);                                  //Definir nivel. Cambia durante el código de la ventana principal
        A->Presentar();                                             //Presentar la primera diapositiva
    }

    if(localizacion%2==1 && localizacion<6){          //....................Añade los personajes a la escena si la localización es algún nivel
        jugadores.push_back(new Aliado(localizacion, vidas));
        if(multijugador == true)
            jugadores.push_back(new Aliado(localizacion+1, vidas));
        for(short int u=0; u<jugadores.size(); u++){
            escena->addItem(jugadores.at(u));
            jugadores.at(u)->setFlag(QGraphicsItem::ItemIsFocusable);
        }
        Trackers();
    }
}

void Juego::actualizar()
{
    /*
     * Método para actualizar las posiciones y valores de los elementos del nivel.
    */
    contTime++;
    AumentarPuntaje();      //Para actualizar el puntaje de los jugadores

    if(localizacion==1){             //............................Nivel 1
        if(contTime%120==0)
            NuevosObstaculos();
        for(int tipo_a=0; tipo_a<jugadores.size(); tipo_a++){
            for(unsigned int m_cae=0; m_cae<(unsigned)meteoritos.size(); m_cae++){
                juego->jugadores.at(tipo_a)->actualizarVida(tipo_a);  //¿Algún meteoro chocó con el personaje?
            }
        }
        for(unsigned short int u=0; u<(unsigned)meteoritos.size(); u++){ //Actualizar meteoritos que caen de la parte superior.
            if(meteoritos.at(u)->getPosicionY()<=400){
                meteoritos.at(u)->ActualizarVelocidad();
                meteoritos.at(u)->ActualizarPosicion();
            }else{
                meteoritos.at(u)->Desaparecer();
                meteoritos.remove(u);
            }
        }
        for(int i=0; i<plataformas.size();i++)
            plataformas.at(i)->Mover(); //Mover plataformas.
        for(unsigned short int u=0; u<(unsigned)jugadores.size(); u++){
            if(jugadores.at(u)->posinicialX_barra==60)     //¿Sobre plataforma en movimiento?
                jugadores.at(u)->actualizarcoordenadas(plataformas.at(1)->getPosY());
            if(jugadores.at(u)->saltando == true)
                jugadores.at(u)->moverY();  //Salta
            else if(jugadores.at(u)->colision_barra==false)
                jugadores.at(u)->moverY(0); //Cae
        }
    }else if(localizacion == 3){     //............................Nivel 2
        ActualizarCountdown();  //Para que se vea el tiempo en pantalla
        actualizarDisparos();
        if(contTime%2==0)
            DisparosEnemigos();     //Elección de qué enemigos dispararán
    }else if(localizacion==5){       //............................Nivel 3
        ActualizarCountdown();  //Para que se vea el tiempo en pantalla
        actualizarDisparos();
        if(contTime%50==0)
            NuevosObstaculos();

        for(int tipo_e=0; tipo_e<EnemEstaticos.size(); tipo_e++){ //Hacer que enemigos en plataformas dispares.
            if(juego->EnemEstaticos.at(tipo_e)->vivo==true && contTime%30==0)
                EnemEstaticos.at(tipo_e)->disparar();
        }
        for(unsigned short int bala_j=0; bala_j<(unsigned)disparosAliados.size(); bala_j++){
            for(int tipo_e=0; tipo_e<Enemigos.size(); tipo_e++)
                juego->Enemigos.at(tipo_e)->actualizarVida();  //¿Algún disparo chocó con una nave enemiga?
        }
        for(int e=0; e<Enemigos.size(); e++){ //Actualizar posición de enemigos que caen y si estos colisionan con las balas de jugador
            if(Enemigos.at(e)->ActualizarPosicion() || juego->Enemigos.at(e)->vivo==false){
                Enemigo *enemigo=Enemigos.at(e);
                escena->removeItem(enemigo);
                Enemigos.removeAt(e);
                delete enemigo;
            }else if(contTime%40==0)
                Enemigos.at(e)->disparar();
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    DisminuirVidas();       //Para actualizar las vidas de los personajes
    ActualizarPuntos();     //Actualiza el estado de las estrellas (desaparecer por tiempo o moverse)

    if(contTime<duracion && (J_vivo[0] || J_vivo[1])){
        if(contTime%(duracion/cantidadMonedas)==0 && juego->getNivel()<3)
            NuevosPuntos();
        if(juego->getNivel()==3 && juego->puntajeNivel>110)
            ReiniciarNivel();   // Perdió

    }if(juego->getNivel()==1 && (J_vivo[0]==false && J_vivo[1]==false)){
        ReiniciarNivel();   // Perdió
    }else if(juego->getNivel()==2 && (contTime>=duracion || (J_vivo[0]==false && J_vivo[1]==false))){
        ReiniciarNivel();   // Perdió
    }else if(juego->getNivel()==3 && (contTime>=duracion || (J_vivo[0]==false && J_vivo[1]==false))){
        ReiniciarNivel();   // Perdió
    }else
        evaluarNivel(); //Evaluar si pasó el nivel
}

void Juego::Trackers()
{
    /*
     Método para inicialización de los elementos de texto agregados a la escena para registro de tiempo, puntajes y vidas.
    */
    Score->setPlainText(QString("Score: ")+QString::number(puntajeNivel));
    Score->setDefaultTextColor(Qt::white);
    Score->setFont(QFont("Book Antiqua", 14));
    Score->setPos(Score->x(),Score->y()+5);
    escena->addItem(Score);

    Lives1->setPlainText(QString("Lives P1: ")+QString::number(jugadores.at(0)->vidas));
    Lives1->setDefaultTextColor(Qt::white);
    Lives1->setFont(QFont("Book Antiqua", 14));
    Lives1->setPos(Lives1->x(),Lives1->y()+25);
    escena->addItem(Lives1);
    if(multijugador==true){
        Lives2->setPlainText(QString("Lives P2: ")+QString::number(jugadores.at(1)->vidas));
        Lives2->setDefaultTextColor(Qt::white);
        Lives2->setFont(QFont("Book Antiqua", 14));
        Lives2->setPos(Lives2->x(),Lives2->y()+45);
        escena->addItem(Lives2);
    }

    if(this->getNivel()!=1)
    {
        Time->setFont(QFont("Book Antiqua", 16));
        Time->setPlainText(QString("Time: ")+TimeAsSting());
        Time->setDefaultTextColor(Qt::white);
        Time->setPos(Time->x()+550,Time->y()+10);
        escena->addItem(Time);
    }
}

void Juego::ActualizarCountdown()
{
    //Actualizar el tiempo en pantalla
    Time->setPlainText(QString("Time: ")+TimeAsSting());
}

QString Juego::TimeAsSting()
{
    //Obtener tiempo restante. Retorna un QString con el formato M:SS (ejemplo: 1:10, 1:05)
    int minutos=0, segundos=0;
    minutos=((duracion-contTime)/65)/60;
    segundos=((duracion-contTime)/65)%60;
    if(segundos>9)
        return QString(QString::number(minutos)+":"+QString(QString::number(segundos)));
    else
        return QString(QString::number(minutos)+":0"+QString(QString::number(segundos)));
}

void Juego::actualizarDisparos()
{
    /*
     Método que actualiza las posiciones de los disparos lanzados por los jugadores y por los enemigos.
     Adicionalmente revisa colisiones con enemigos y aliados o desaparición de la escena.
    */
    for(unsigned short int bala_j=0; bala_j<(unsigned)disparosAliados.size(); bala_j++){ //Actualizar balas aliadas
        for(int tipo_e=0; tipo_e<EnemEstaticos.size(); tipo_e++)
            juego->EnemEstaticos.at(tipo_e)->actualizarVida();  //¿Algún disparo chocó con una nave enemiga?
        if(disparosAliados.at(bala_j)->y()<0 ||
                (disparosAliados.at(bala_j)->x()<0 || disparosAliados.at(bala_j)->x()>680)){
            escena->removeItem(disparosAliados.at(0));
            disparosAliados.pop_front();
        }else{
            disparosAliados.at(bala_j)->ActualizarVelocidad();
            disparosAliados.at(bala_j)->ActualizarPosicion();
        }
    }
    for(unsigned int bala_e=0; bala_e<(unsigned)disparosEnemigos.size(); bala_e++){ //Actualización de las balas del enemigo
        for(int tipo_a=0; tipo_a<jugadores.size(); tipo_a++)
            juego->jugadores.at(tipo_a)->actualizarVida(tipo_a);  //¿Algún disparo chocó con un personaje aliado?
        if(disparosEnemigos.at(bala_e)->y()>400 && juego->getNivel()==2){
            escena->removeItem(disparosEnemigos.at(bala_e));
            disparosEnemigos.remove(bala_e);
        }else if(juego->getNivel()==2){
            disparosEnemigos.at(bala_e)->ActualizarVelocidad();
            disparosEnemigos.at(bala_e)->ActualizarPosicion();
        }else if(disparosEnemigos.at(bala_e)->Mover()){
            escena->removeItem(disparosEnemigos.at(bala_e));
            disparosEnemigos.remove(bala_e);
        }
    }
}

void Juego::evaluarNivel()
{
    /*
     Método que evalúa requisitos para el cambio de nivel.
    */
    estado = false;
    if(juego->getNivel()==1){ //Requisitos nivel 1
        for(unsigned short int n=0; n<(unsigned)jugadores.size(); n++){
            if(jugadores.at(n)->NivelSuperado==true && jugadores.at(n)->vivo==true){
                estado = true;
                break;
            }
        }
        if(estado==true)
            juego->CambiarLocalizacion();
    }
    else if(juego->getNivel()==2){ //Requisitos nivel 2
        estado=true;
        for(unsigned short int n=0; n<(unsigned)Enemigos.size(); n++){
            if(Enemigos.at(n)->vivo==true){
                estado=false;
                break;
            }
        }
        if(puntajeNivel>=120 && estado==true)
            juego->CambiarLocalizacion();
    }
    else if(juego->getNivel()==3){ //Requisitos nivel 3
        estado=true;
        for(unsigned short int n=0; n<(unsigned)EnemEstaticos.size(); n++){
            if(EnemEstaticos.at(n)->vivo==true){
                estado=false;
                break;
            }
        }
        if(estado==true && puntajeNivel<=110)
            juego->CambiarLocalizacion();
    }
}

void Juego::DisparosEnemigos()
{
    //Método que elige al azar enemigos del nivel dos que dispararán.
    if(juego->getNivel()==2)
    {
        int n = rand()%(EnemEstaticos.size());
        if(contTime%10==0 && EnemEstaticos.size()>0){
            int EnemDisparando=rand()%(EnemEstaticos.size()+1);
            for(int i=0;i<=EnemDisparando;i++){
                if(EnemEstaticos.at(n)->vivo==true)
                    EnemEstaticos.at(n)->disparar();
            }
        }
    }
}

void Juego::DisminuirVidas()
{
    //Método que modifica en pantalla las vidas de los jugadores.
    if(jugadores.size()>0){
        Lives1->setPlainText(QString("Lives P1: ")+QString::number(jugadores.at(0)->vidas));
        if(multijugador==true){
            Lives2->setPlainText(QString("Lives P2: ")+QString::number(jugadores.at(1)->vidas));
        }
    }
}

void Juego::AumentarPuntaje()
{
    //Método para actualizar el puntaje en pantalla.
    Score->setPlainText(QString("Score: ")+QString::number(puntajeNivel));
}

void Juego::NuevosObstaculos()
{
    //Método que agrega obstáculos al azar según el nivel.
    if(juego->getNivel()==1){ //Agrega meteoritos que caen con una velocidad inicial y en ángulo de 3Pi/2.
        meteoritos.push_back(new Meteorito(0,9,(rand() % 650 + 10),0,20));
        escena->addItem(meteoritos.back());
    }else if(juego->getNivel()==3){ //Añade enemigos que caen en el nivel tres con posición X inicial al azar y ángulo de disparo de 3Pi/2.
        int posX=120+rand()%(451);
        if(contTime%3==0)
            Enemigos.push_back(new Enemigo(4,1,1,posX,0,posX+30,60,posX,0,0,5,3*M_PI_2,4,20));
        else
            Enemigos.push_back(new Enemigo(5,1,1,posX,0,posX+30,60,posX,0,0,5,3*M_PI_2,4,20));
        escena->addItem(Enemigos.back());
    }
}

void Juego::ActualizarPuntos()
{
    //Método que actualiza las posiciones de las estrellas de los niveles 1 y 2, actualiza el tiempo que permanecen en escena
    //Y determina si el jugador las alcanza para aumentar el puntaje.
    if(estrellas.size()!=0 && juego->getNivel()<3){ //Actualización de tiempos de monedas
        for(int i=0; i<estrellas.size();i++){
            if(estrellas.at(i)->getTiempo()>0)
                estrellas.at(i)->setTiempo(estrellas.at(i)->getTiempo()-1);
            else if(estrellas.at(i)->getValor()>0){
                escena->removeItem(estrellas.at(i));
                estrellas.at(i)->hide();
                estrellas.removeAt(i);
            }
        }
    }
    for(unsigned int n=0; n<(unsigned)estrellas.size(); n++){
        estrellas.at(n)->Mover();
        estrellas.at(n)->AumentarPuntaje(n);
    }
}

void Juego::NuevosPuntos()
{
    //Método que añade estrellas a la escena según el nivel y con parámetros ajustados a las necesidades.
    if(juego->getNivel()==1 && estrellas.size()==0)
        estrellas.push_back(new Moneda(0,15,10,530,60,0.2,1,duracion));
    else if(juego->getNivel()==1 && estrellas.size()>0)
        estrellas.push_back(new Moneda(2,9.2,3.5,rand() % 650 + 10,370,0.1, 2, 100));
    else if(juego->getNivel()==2)
        estrellas.push_back(new Moneda(5,9,6,5+(std::rand()%(671)),110+(std::rand()%(271-110)),0.1, 3, 150));
    escena->addItem(estrellas.back());
}

int Juego::getNivel()
{
    //Método que determina el nivel en el que se encuentra el usuario.
    if(localizacion==1) //Significa que se encuentra en el nivel 1
        return localizacion;
    else if(localizacion==3) //Significa que se encuentra en el nivel 2
        return localizacion-1;
    else if(localizacion==5) //Significa que se encuentra en el nivel 3
        return localizacion-2;
    else
        return 100; //No se encuentra en ningun nivel
}

void Juego::ReiniciarNivel()
{
    //Método que limpia la escena de juego e inicia uno nuevo.
    J_vivo[0]=J_vivo[1]=false;
    escena->clear();
    timer->stop();
    estado_juego = false;
    juego = new Juego();
}

void Juego::CambiarLocalizacion()
{
    //Método para almacenamiento de la información al cambiar de nivel y para comenzar el nuevo nivel.
    if(localizacion==5){
        //Actualiza la puntuación local (se guardan los puntajes y los niveles en el archivo de los usuarios del sistema)
        infoUsuario.int1 += puntajeNivel;
        infoUsuario.int2 +=1;                   //Pasar a otra localización
        Escritor().actualizarInfoLocal();
        //Se guarda el puntaje si fue mayor a la anterior ocasión
        Escritor().actualizarInfoGeneral();
    }else if(localizacion<=6 && localizacion!=5){
        //Actualiza la puntuación local (se guardan los puntajes y los niveles en el archivo del usuario)
        infoUsuario.int1 += puntajeNivel;
        infoUsuario.int2 +=1;                   //Pasar a otra localización
        Escritor().actualizarInfoLocal();
    }else if(localizacion>6 && localizacion!=5){
        //Reinicia la información local
        infoUsuario.string2 = nombreUsuario;
        infoUsuario.int1 = 0;                   //Se reinicia el puntaje
        infoUsuario.int2 = 0;                   //Se reinicia la localización
        Escritor().actualizarInfoLocal();
    }

    escena->clear();
    delete this;
    if(localizacion%2==1)
        timer->stop();
    if(localizacion<=6)
        juego = new Juego();
    else if(localizacion==8){
        escena->setBackgroundBrush(QPixmap(":/final/Informacion/puntajes.jpg").scaled(680,400));
        p = new Puntaje();
    }
}

Animacion *Juego::getA() const
{
    return A;
}
