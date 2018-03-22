#include "histogram.h"
#include "ui_histogram.h"

Histogram::Histogram(QWidget *parent, QStringList *Mf, QList<int> *Mk) :
    QDialog(parent),
    ui(new Ui::Histogram)
{
    ui->setupUi(this);
    QIcon infoIcon(":/new/prefix1/icon/diagram.ico");
    this->setWindowIcon(infoIcon);
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setAttribute(Qt::WA_DeleteOnClose, true);
    Mfr = Mf;
    Make = Mk;
    resize(500,350);
    setWindowTitle(tr("Histogram"));
    customPlot = new QCustomPlot(this);
    vbox = new QVBoxLayout(this);
    vbox->addWidget(customPlot);
    setLayout(vbox);
    rndres();
}

Histogram::~Histogram()
{
    delete ui;
}

void Histogram::rndres()
{
    int g;
    fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    customPlot->addPlottable(fossil);
    // Установки цвета:
    QPen pen;
    pen.setWidthF(1.5);//Толщина контура столбца
    fossil->setName(tr("Histogram")); // Легенда
    pen.setColor(QColor(50, 50, 100));// Цвет контура столбца
    fossil->setPen(pen);
    // Цвет самого столбца, четвертый параметр - прозрачность
    fossil->setBrush(QColor(50, 50, 250, 70));

    // Установки значений оси X:
    QVector<double> ticks;
    QVector<QString> labels;
    int l = Mfr->size();
    for (g = 1; g <= l*2; g+=2)
    {
        ticks << g;
    }
    for (g = 0; g < l; g++)
    {
        labels << Mfr->value(g);
    }
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, l*2);

    // Установки значений оси Y:
    int m = 0;
    int o;
    for (g = 0; g < l; g++)
    {
        o = Make->value(g);
        if (o > m)
            m = o;
    }
    QVector<double> ticks1;
    for (g = 0; g <= m; g++)
    {
        ticks1 << g;
    }
    customPlot->yAxis->setAutoTicks(false);
    customPlot->yAxis->setAutoTickStep(false);
    customPlot->yAxis->setRange(0, m);
    customPlot->yAxis->setTickVector(ticks1);
    customPlot->yAxis->setLabel(tr("Number of models"));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Данные:
    QVector<double> fossilData;
    qsrand (time(NULL));
    for (g = 0; g < l; g++)
    {
        o = Make->value(g);
        fossilData << o;
    }
    fossil->setData(ticks, fossilData);
    customPlot->replot();
}
