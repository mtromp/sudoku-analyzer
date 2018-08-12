#ifndef SUDOKUCELLVIEW_H
#define SUDOKUCELLVIEW_H

#include <QGraphicsItem>

class SudokuCellView : public QGraphicsItem
{
public:
    SudokuCellView();
    virtual ~SudokuCellView();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // SUDOKUCELLVIEW_H

