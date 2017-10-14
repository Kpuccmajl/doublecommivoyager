#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);

    res = new Results();
    switcher = false;
}

void Gui::drawPoints(QPainter &painter)
{

    painter.setPen(QPen(Qt::red, 3, Qt::SolidLine));

    foreach (QPoint pnt, leftPnts) {
        painter.drawPoint(pnt);
    }

    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));

    foreach (QPoint pnt, rightPnts) {
        painter.drawPoint(pnt);
    }
}

void Gui::drawCurve(QPainter &painter, QVector<QPoint> &pnts)
{
    algorythm algo;
    qreal maxDist = 0, dist;
    for (int i = 0 ; i < pnts.count() - 1; i++)
    {
        dist = algo.calcDistance(pnts.at(i), pnts.at(i + 1));
        if (dist > maxDist)
        {
            maxDist = dist;
        }
    }

    for (int i = 0; i < pnts.count() - 1; i++)
    {
        if ((int)algo.calcDistance(pnts.at(i), pnts.at(i+1)) != (int)maxDist)
        {
            painter.drawLine(pnts.at(i), pnts.at(i+1));
        }
        else if (pnts.count() == 3)
        {
            painter.drawLine(pnts.at(i), pnts.at(i+1));
        }
    }

}


Gui::~Gui()
{
    delete ui;
}

void Gui::paintEvent(QPaintEvent *event)
{
    event = NULL;
    QPainter painter(this);
    Gui::drawPoints(painter);
    QTime start = QTime::currentTime();

    if (leftPnts.count() != 0 && rightPnts.count() != 0)
    {
        QVector<QPoint> left, right;
        QFuture< QVector<QPoint> > future = QtConcurrent::run(this, &Gui::calcPath, leftPnts);
        QFuture< QVector<QPoint> > future2= QtConcurrent::run(this, &Gui::calcPath, rightPnts);


        future.waitForFinished();
        future2.waitForFinished();

        left = future.result();
        right = future2.result();

        painter.setPen(QPen(Qt::red, 1, Qt::DashLine));
        Gui::drawCurve(painter, left);

        painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
        Gui::drawCurve(painter, right);
    }

    ui->lblTime->setText(QString::number(start.elapsed()));
}


QVector<QPoint> Gui::calcPath(QVector<QPoint> &pnts)
{
    QVector<QPoint> final;

    algorythm algo;

    algo.s = 0;
    algo.n = pnts.count();
    algo.min = 32676;

    for (int i = 1; i <= algo.n; i++)
    {
        algo.m[i] = 0;
    }

    algo.count = 1;
    algo.m[1] = algo.count;

    for (int i = 1; i <= pnts.count(); i++)
    {
        for (int j = 1; j <= pnts.count(); j++)
        {
            if (i == j)
            {
                algo.a[i][j] = 0;
            }
            else
            {
                algo.a[i][j] = algo.calcDistance(pnts.at(i - 1), pnts.at (j - 1));
                algo.a[j][i] = algo.a[i][j];
            }
        }
    }

    algo.search(1); //commivoyager start

    int c = 1;

    for (int i = 1; i <= pnts.count(); i++)
    {
        int j = 1;
        while ((j < pnts.count()) && (algo.minm[j] != c))
        {
            j++;
        }

        final.append(pnts.at(j-1));
        c++;
    }

    final.append(pnts.at(0));

    return final;
}

void Gui::on_btnInit_clicked()
{
    leftPnts.clear();
    rightPnts.clear();

    qsrand(QTime::currentTime().msec());

    for (int i = 0; i < ui->sBox1->value(); i++)
        leftPnts.append(QPoint(qrand()%200+100, qrand()%200+100));
    for (int i = 0; i < ui->sBox2->value(); i++)
        rightPnts.append(QPoint(qrand()%200+400, qrand()%200+100));

    update();
}

void Gui::on_btnEx_clicked()
{
    if (switcher == false)
    {
        switcher = true;
        //Posled
        ui->sBox1->setValue(1);
        ui->sBox2->setValue(ui->sboxPoints->value());
        emit on_btnInit_clicked();
        posledRes.append(ui->lblTime->text().toInt() * 2);
    }
    else
    {
        //Parall
        ui->sBox1->setValue(ui->sboxPoints->value());
        ui->sBox2->setValue(ui->sboxPoints->value());
        switcher = false;
        emit on_btnInit_clicked();
        parallRes.append(ui->lblTime->text().toInt());
    }
    res->show();
    res->posled = posledRes;
    res->paral = parallRes;
    res->update();
}
