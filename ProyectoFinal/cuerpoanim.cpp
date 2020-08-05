#include "cuerpoanim.h"
#include <math.h>
#include <cmath>
#include <QGraphicsRectItem>

CuerpoAnim::CuerpoAnim(double _masa,double _PX,double _PY,double _VX,double _VY)
{
    //Constructor. Se define la constante gravitacional, la masa del cuerpo y se obtienen valores iniciales de posición y velocidad.
    G=0.00000006673;
    masa=_masa;
    PX=_PX;
    PY=_PY;
    VX=_VX;
    VY=_VY;
    QPixmap Pixmap(":/simulacion/Simulacion del comic/sol animacion.png");
    setPixmap(Pixmap.scaled(QSize(20,20)));
}

void CuerpoAnim::actualizar()
{
    //Actualización de posición del cuerpo según ecuaciones de para movimiento planetario.
    for(int i=0;i<planetas.size();i++){
        if(planetas[i]!=this){
            masa2=planetas[i]->getMasa();
            PX2=planetas[i]->getPX();
            PY2=planetas[i]->getPY();
        }
    }
    distancia=pow((PX2-PX)*(PX2-PX)+(PY2-PY)*(PY2-PY),1/2);
    angulo=atan2((PY2-PY),(PX2-PX));
    AX=((G*masa2)/(distancia*distancia))*cos(angulo);
    AY=((G*masa2)/(distancia*distancia))*sin(angulo);
    VX=VX+AX*DT;
    VY=VY+AY*DT;
    PX=PX+VX*DT+(AX*DT*DT);
    PY=PY+VY*DT+(AY*DT*DT);
    setPos(PX*0.5,PY*0.5);
}

void CuerpoAnim::setMasa2(double value)
{
    masa2 = value;
}

double CuerpoAnim::getPX() const
{
    return PX;
}

double CuerpoAnim::getPY() const
{
    return PY;
}

void CuerpoAnim::setPlanetas(const QList<CuerpoAnim *> &value)
{
    planetas = value;
}

double CuerpoAnim::getMasa() const
{
    return masa;
}
