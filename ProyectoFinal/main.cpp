#include "ventanalogin.h"
#include <QApplication>
#include <QMediaPlayer>
QMediaPlayer *musica = new QMediaPlayer();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaLogin wL;
    wL.show();

    return a.exec();
}
