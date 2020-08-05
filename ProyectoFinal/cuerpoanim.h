#ifndef CUERPOANIM_H
#define CUERPOANIM_H


#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsPixmapItem>
#include <QList>

class CuerpoAnim:public QObject,public QGraphicsPixmapItem
{
public:
    CuerpoAnim(double _masa,double _PX,double _PY,double _VX,double _VY);

    void setPlanetas(const QList<CuerpoAnim *> &value);
    void setMasa2(double value);
    double getMasa() const;
    double getPX() const;
    double getPY() const;

private:
    QList<CuerpoAnim *> planetas;
    double distancia,masa,angulo,AX,AY,PX,PY,DT=1,VX,VY;
    double masa2,PX2,PY2,G;

public slots:
    void actualizar();
};

#endif // CUERPOANIM_H
