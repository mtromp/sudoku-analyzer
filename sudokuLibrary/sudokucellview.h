#ifndef SUDOKUCELLVIEW_H
#define SUDOKUCELLVIEW_H

#include <QGraphicsItem>

class SudokuCellView : public QGraphicsItem
{
public:
    SudokuCellView(QGraphicsItem* parent = nullptr);
    virtual ~SudokuCellView();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void handleMouseEvent();

private:
    int theValue;
};

#endif // SUDOKUCELLVIEW_H

