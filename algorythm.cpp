#include "algorythm.h"

algorythm::algorythm(QObject *parent) :
    QObject(parent)
{
}

qreal algorythm::calcDistance(QPoint p1, QPoint p2)
{
    return qSqrt(qPow((p2.x() - p1.x()), 2) + qPow((p2.y() - p1.y()), 2));
}

void algorythm::search(int x)
{
    if ((count == n) &&
            (a[x][1] != 0) &&
            (s + a[x][1] < min))
    {
        min = s + a[x][1];
        for (int i = 1; i < n; i++)
        {
            minm[i] = m[i];
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if ((i != x)&&
                    (a[x][i] != 0) &&
                    (m[i] == 0) &&
                    (s + a[x][i] < min))
            {
                s += a[x][i];
                count++;
                m[i] = count;
                search(i);
                m[i] = 0;
                count--;
                s -= a[x][i];
            }
        }
    }
}
