#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
}

Results::~Results()
{
    delete ui;
}

void Results::paintEvent(QPaintEvent *)
{
    Results::drawResults();
}

void Results::drawResults()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue,3,Qt::SolidLine));
    int inter = 3;
    foreach (int i, posled)
    {
        painter.drawPoint(50+inter, i   + 50  );
        inter += 3;
    }
    inter = 3;
    painter.setPen(QPen(Qt::red,3,Qt::SolidLine));
    foreach (int i, paral)
    {
        painter.drawPoint(50+inter, i + 50);
        inter += 3;
    }
    painter.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    inter = 3;
    for (int i = 0; i < posled.count() - 1; i++)
    {
        painter.drawLine(50 + inter, posled.at(i)  + 50,
                         50 + inter + 3, posled.at(i+1)  + 50);
        inter += 3;
    }
    painter.setPen(QPen(Qt::red,1,Qt::SolidLine));
    inter = 3;
    for (int i = 0; i < paral.count() - 1; i++)
    {
        painter.drawLine(50 + inter, paral.at(i)  + 50,
                         50 + inter + 3, paral.at(i+1)   + 50);
        inter += 3;
    }
}
