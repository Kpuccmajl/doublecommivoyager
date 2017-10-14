#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

namespace Ui {
class Results;
}

class Results : public QWidget
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0);
    ~Results();

    void paintEvent(QPaintEvent *);
    QList<int> posled;
    QList<int> paral;
    void drawResults();

private:
    Ui::Results *ui;
};

#endif // RESULTS_H
