#include "resultplotqwt.h"
#include "qwt_plot.h"
#include <QGridLayout>

ResultPlotQwt::ResultPlotQwt(QWidget *parent) :
    ResultPlotSuper(parent)
{
    plot = new QwtPlot(this);

    QGridLayout *lyt = new QGridLayout(this);
    lyt->addWidget(plot,0,0);
    lyt->setMargin(0);
    this->setLayout(lyt);

}

ResultPlotQwt::~ResultPlotQwt()
{
    delete plot;
}

void ResultPlotQwt::plotResults(QVector<QVector<double> *> &y,
                                QVector<QVector<double> *> &x)
{
    /*
     * MAKE SURE THE LENGTH OF THE VECTORS IN ALL PLOTS MATCHES THE ACTUAL PILE
     *
     * NO MORE RANGE CHECKING!
     */

#if 0
    QVector<double> *xOffset;

    int numPiles = x.size();

    int maxPts = -1;

    for (int i=0; i<numPiles; i++)
    {
        if (x[i]->size() > maxPts)
        {
            maxPts = x[i]->size();
            xOffset = y[i];
        }
    }

    plot->clearPlottables();

    plot->autoAddPlottableToLegend();
    plot->legend->setVisible(true);

    plot->addGraph();
    plot->graph(0)->setData(QVector<double>(maxPts, 0.0),*xOffset);
    plot->graph(0)->setPen(QPen(Qt::black));
    plot->graph(0)->removeFromLegend();

    for (int ii=0; ii<numPiles; ii++) {
        QCPCurve *mCurve = new QCPCurve(plot->xAxis, plot->yAxis);
        mCurve->setData(*x[ii],*y[ii]);
        mCurve->setPen(QPen(LINE_COLOR[ii], 3));
        mCurve->setName(QString("Pile #%1").arg(ii+1));
    }

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    plot->axisRect()->autoMargins();
    plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignBottom);
    plot->rescaleAxes();
    plot->replot();
#endif
}
