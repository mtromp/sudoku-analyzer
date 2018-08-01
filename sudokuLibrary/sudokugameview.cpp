#include "sudokugameview.h"
#include "sudokugamescene.h"

SudokuGameView::SudokuGameView(QWidget *parent) : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameStyle(QFrame::NoFrame);

    this->setBackgroundBrush(QColor(114, 213, 175));
    this->setScene(new SudokuGameScene(this));
}

SudokuGameView::~SudokuGameView()
{

}
