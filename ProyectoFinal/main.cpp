#include "ventanalogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaLogin wL;
    wL.show();

    return a.exec();
}
