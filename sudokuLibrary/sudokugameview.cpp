#include "sudokugameview.h"

SudokuGameView::SudokuGameView(QWidget *parent) : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameStyle(QFrame::NoFrame);

    this->setBackgroundBrush(QColor(114, 273, 175));
}
