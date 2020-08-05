#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include "juego.h"

extern QGraphicsScene *escena;
extern Juego *juego;

VentanaJuego::VentanaJuego(QWidget *parent) : QMainWindow(parent), ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);
    playlist->addMedia(QUrl("qrc:/sonidos/Otros recursos/nocturnal.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);    //Se genera un loop con la musica de fondo que se desea
    musica->setPlaylist(playlist);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,680,400);
    ui->Grafica->setScene(escena);
    ui->Grafica->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Grafica->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->installEventFilter(this);
    srand(unsigned(time(nullptr)));
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}

void VentanaJuego::on_actionMusica_triggered()
{
    if(musica->state() == QMediaPlayer::PlayingState)
        musica->stop();
    else
        musica->play();
}

void VentanaJuego::on_actionSobrePersonajes_triggered()
{
    QDialog *dialog = new QDialog();
    dialog->setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
    dialog->setWindowTitle("Players information");
    dialog->setGeometry(this->x(),this->y(),500,500);
    dialog->setFixedSize(500,500);
    dialog->setStyleSheet("background-color:black;");
    dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QLabel *label = new QLabel(dialog);
    label->setPixmap(QPixmap(":/info/Informacion/Personajes_Desc_.jpg").scaled(500,500));

    dialog->setModal(true);
    dialog->setVisible(true);
}

void VentanaJuego::on_actionInstrucciones_triggered()
{
    if(juego->getNivel()<5)
    {
        QDialog *dialog = new QDialog();
        dialog->setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
        dialog->setWindowTitle("Level " + QString::number(juego->getNivel()) + " information");
        dialog->setGeometry(this->x(),this->y(),300,300);
        dialog->setFixedSize(300,300);
        dialog->setStyleSheet("background-color:black;");
        dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);

        QLabel *label = new QLabel(dialog);
        label->setPixmap(QPixmap(":/info/Informacion/level"+QString::number(juego->getNivel())+".jpg").scaled(300,300));

        dialog->setModal(true);
        dialog->setVisible(true);
    }
}

void VentanaJuego::on_actionHistoria_triggered()
{
    if(juego->getNivel()<5)
    {
        QDialog *dialog = new QDialog();
        dialog->setWindowIcon(QIcon(":/iconos/Iconos/iconW_nave.png"));
        dialog->setWindowTitle("Story summary level " + QString::number(juego->getNivel()));
        dialog->setGeometry(this->x(),this->y(),350,350);
        dialog->setFixedSize(350,350);
        dialog->setStyleSheet("background-color:black;");
        dialog->setWindowFlags(dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);

        QLabel *label = new QLabel(dialog);
        label->setPixmap(QPixmap(":/info/Informacion/chapter"+QString::number(juego->getNivel())+".jpg").scaled(350,350));

        dialog->setModal(true);
        dialog->setVisible(true);
    }
}

void VentanaJuego::on_inicioJuego_clicked()
{
    if((juego->getNivel()>0 && juego->getNivel()<4) && (juego->estado_juego==false)){
        juego->timer = new QTimer;
        connect(juego->timer,SIGNAL(timeout()),this,SLOT(actualizar()));
        juego->timer->start(dt);
        estado=juego->estado_juego = true;
    }
}

void VentanaJuego::on_pausaJuego_clicked()
{
    if((juego->getNivel()>0 && juego->getNivel()<4) && (juego->estado_juego==true)){
        juego->timer->stop();
        estado=juego->estado_juego = false;
    }
}

void VentanaJuego::actualizar()
{
    juego->actualizar();
}

bool VentanaJuego::eventFilter(QObject *obj, QEvent *event)
{
    if (!estado)
        return false;
    if((event->type()==QEvent::KeyPress && (juego->getNivel()>0 && juego->getNivel()<4)) && juego->estado_juego==true)
    {
        pressedKeys += ((QKeyEvent*)event)->key();
        ///////////////////////////////////////////////////////// IZQUIERDA
        if(pressedKeys.contains(Qt::Key_A) && juego->J_vivo[0]==true)
            juego->jugadores.at(0)->calcularmovimiento(Qt::Key_A);
        if((pressedKeys.contains(Qt::Key_H) && juego->getModoJuego()==true) && juego->J_vivo[1]==true)
            juego->jugadores.at(1)->calcularmovimiento(Qt::Key_A);
        ///////////////////////////////////////////////////////// DERECHA
        if(pressedKeys.contains(Qt::Key_S) && juego->J_vivo[0]==true)
            juego->jugadores.at(0)->calcularmovimiento(Qt::Key_S);
        if((pressedKeys.contains(Qt::Key_J) && juego->getModoJuego()==true) && juego->J_vivo[1]==true)
            juego->jugadores.at(1)->calcularmovimiento(Qt::Key_S);
        ///////////////////////////////////////////////////////// SALTAR
        if(pressedKeys.contains(Qt::Key_W) && juego->J_vivo[0]==true)
            juego->jugadores.at(0)->calcularmovimiento(Qt::Key_W);
        if((pressedKeys.contains(Qt::Key_U) && juego->getModoJuego()==true) && juego->J_vivo[1]==true)
            juego->jugadores.at(1)->calcularmovimiento(Qt::Key_W);
        ///////////////////////////////////////////////////////// DISPARAR
        if(pressedKeys.contains(Qt::Key_D) && juego->J_vivo[0]==true)
            juego->jugadores.at(0)->calcularmovimiento(Qt::Key_D);
        if((pressedKeys.contains(Qt::Key_K) && juego->getModoJuego()==true) && juego->J_vivo[1]==true)
            juego->jugadores.at(1)->calcularmovimiento(Qt::Key_D);
        ///////////////////////////////////////////////////////// MOVER-ARMA DERECHA
        if(pressedKeys.contains(Qt::Key_R) && juego->J_vivo[0]==true)
            juego->jugadores.at(0)->calcularmovimiento(Qt::Key_R);
        if((pressedKeys.contains(Qt::Key_O) && juego->getModoJuego()==true) && juego->J_vivo[1]==true)
            juego->jugadores.at(1)->calcularmovimiento(Qt::Key_R);
        ///////////////////////////////////////////////////////// MOVER-ARMA IZQUIERDA
        if(pressedKeys.contains(Qt::Key_F) && juego->J_vivo[0]==true)
            juego->jugadores.at(0)->calcularmovimiento(Qt::Key_F);
        if((pressedKeys.contains(Qt::Key_L) && juego->getModoJuego()==true) && juego->J_vivo[1]==true)
            juego->jugadores.at(1)->calcularmovimiento(Qt::Key_F);
    }
    else if(event->type()==QEvent::KeyRelease)
    {
        pressedKeys -= ((QKeyEvent*)event)->key();
    }
    return false;
}

void VentanaJuego::keyPressEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_X && juego->getA()->getActivado())){
        if(!(juego->estado_juego))
            juego->getA()->Presentar();
    }
}
