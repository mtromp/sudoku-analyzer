#ifndef SUDOKUGAMEVIEW_H
#define SUDOKUGAMEVIEW_H

#include <QGraphicsView>
#include "sudokugamescene.h"
#include "sudokucellview.h"

// Same as SudokuView from Wim Leers
class SudokuGameView : public QGraphicsView
{
    Q_OBJECT
public:
    SudokuGameView(SudokuGameScene* gameScene, QWidget* parent = nullptr);

private:
    SudokuGameScene* gameScene;
};

#endif // SUDOKUGAMEVIEW_H
