#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);
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

Gui::~Gui()
{
    delete ui;
}

void Gui::paintEvent(QPaintEvent *event)
{
    event = NULL;
    QPainter painter(this);
    Gui::drawPoints(painter);
}

void Gui::on_btnInit_clicked()
{
    leftPnts.clear();
    rightPnts.clear();

    qsrand(QTime::currentTime().msec());

    for (int i = 0; i < ui->sBox1->value(); i++)
        leftPnts.append(QPoint(qrand()%200+100, qrand()%200+100));
    for (int i = 0; i < ui->sBox2->value(); i++)
        rightPnts.append(QPoint(qrand()%200+400, qrand()%100+200));

    leftPnts.append(rightPnts.last());

    repaint();
}
