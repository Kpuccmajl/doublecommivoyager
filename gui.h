#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QThread>
#include <QVector>
#include <QDebug>
#include "algorythm.h"
#include <QFuture>
#include <QtConcurrentRun>
#include "results.h"

namespace Ui {
class Gui;
}

class Gui : public QWidget
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = 0);
    ~Gui();

    QVector<QPoint> leftPnts;
    QVector<QPoint> rightPnts;

    void drawPoints(QPainter &);
    void drawCurve(QPainter&, QVector<QPoint>&);
    QVector<QPoint> calcPath(QVector<QPoint>&);

    QList<int> posledRes, parallRes;
    bool switcher;

    Results *res;

    void paintEvent(QPaintEvent *);
private slots:

    void on_btnInit_clicked();

    void on_btnEx_clicked();

private:
    Ui::Gui *ui;
};

#endif // GUI_H
