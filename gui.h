#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QThread>
#include <QVector>

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

    void paintEvent(QPaintEvent *);
private slots:

    void on_btnInit_clicked();

private:
    Ui::Gui *ui;
};

#endif // GUI_H
