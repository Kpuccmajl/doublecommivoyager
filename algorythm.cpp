#include "algorythm.h"

algorythm::algorythm(QObject *parent) :
    QObject(parent)
{
}

qreal algorythm::calcDistance(QPoint p1, QPoint p2)
{
    return qSqrt(qPow((p2.x() - p1.x()), 2) + qPow((p2.y() - p1.y()), 2));
}

void algorythm::search(int)
{

}
