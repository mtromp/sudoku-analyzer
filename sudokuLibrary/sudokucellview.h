#ifndef SUDOKUCELLVIEW_H
#define SUDOKUCELLVIEW_H

#include "sudokucell.h"

#include <QGraphicsItem>

class SudokuCellView : public QGraphicsItem
{
public:
    SudokuCellView(SudokuCell* aCell = nullptr
                  , QGraphicsItem* parent = nullptr);
    virtual ~SudokuCellView();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void handleMouseEvent();

private:
    unsigned int theValue;
    SudokuCell* theCell;
};

#endif // SUDOKUCELLVIEW_H

