#ifndef SUDOKUCELLVIEW_H
#define SUDOKUCELLVIEW_H

#include <QObject>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QPointF>
#include <QLinearGradient>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QKeyEvent>
#include <math.h>
#include "dimensions.h"

class SudokuCellView : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    SudokuCellView(void);

    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

private:
    QRect getBoundingRectForChoiceByCoords(int x, int y) const;
    QRect getBoundingRectForChoice(int number) const;

    static QLinearGradient getBackgroundGradient(void);
    // Values.
    int m_x, m_y;
    // States.
    bool m_focus;
    bool m_generated;
};

#endif // SUDOKUCELLVIEW_H
