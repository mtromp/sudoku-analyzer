#ifndef SUDOKUGAMEVIEW_H
#define SUDOKUGAMEVIEW_H

#include <QGraphicsView>

class SudokuGameView : public QGraphicsView
{
    Q_OBJECT

public:
    SudokuGameView(QWidget* parent = nullptr);
};

#endif // SUDOKUGAMEVIEW_H
