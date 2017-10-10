#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPainter>
#include <QTime>

namespace Ui {
class Gui;
}

class Gui : public QWidget
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = 0);
    ~Gui();

    QList<QPoint> list1;
    QList<QPoint> list2;

    void drawPoints(QPainter &);

    void paintEvent(QPaintEvent *);
private slots:

private:
    Ui::Gui *ui;
};

#endif // GUI_H
