#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include <QObject>
#include <qmath.h>
#include <QPoint>

class algorythm : public QObject
{
    Q_OBJECT
public:
    explicit algorythm(QObject *parent = 0);

    static const int maxn = 16;
    int s, n, min, count;
    int m[maxn], minm[maxn];
    qreal a[maxn][maxn];

    qreal calcDistance(QPoint p1, QPoint p2);
    void search(int);

signals:

public slots:

};

#endif // ALGORYTHM_H
