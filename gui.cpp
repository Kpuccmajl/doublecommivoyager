#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);

    qsrand(QTime::currentTime().msec());

    for (int i = 0; i < ui->sBox1->value(); i++)
        list1.append(QPoint(qrand()%200+100, qrand()%200+100));
    for (int i = 0; i < ui->sBox2->value(); i++)
        list2.append(QPoint(qrand()%200+400, qrand()%100+200));
}

void Gui::drawPoints(QPainter &painter)
{

    painter.setPen(QPen(Qt::red, 3, Qt::SolidLine));

    foreach (QPoint pnt, list1) {
        painter.drawPoint(pnt);
    }

    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));

    foreach (QPoint pnt, list2) {
        painter.drawPoint(pnt);
    }
}

Gui::~Gui()
{
    delete ui;
}

void Gui::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    Gui::drawPoints(painter);
}
