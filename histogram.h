#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include "qcustomplot.h"

namespace Ui {
class Histogram;
}
/*!
    \brief Класс, рисующий гистограмму

    Данный класс рисует гистограмму показывающую зависимость количества моделей от производителя.
*/
class Histogram : public QDialog
{
    Q_OBJECT

public:
    explicit Histogram(QWidget *parent = 0, QStringList *Mf = 0, QList<int> *Mk = 0);
    ~Histogram();
private slots:
    ///Функция которая рисует гистограмму, по данным полученным в конструкторе класса
    void rndres();

private:
    Ui::Histogram *ui;
    QCustomPlot *customPlot;
    QVBoxLayout *vbox;
    QCPBars *fossil;
    QList<int> *Make;
    QStringList *Mfr;

};

#endif // HISTOGRAM_H
