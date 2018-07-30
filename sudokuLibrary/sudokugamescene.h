#ifndef SUDOKUGAMESCENE_H
#define SUDOKUGAMESCENE_H

#include "sudokucellview.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class SudokuCellView;

class SudokuGameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SudokuGameScene(QObject* parent = nullptr);
    virtual ~SudokuGameScene(void);

    void renderBoard(QPainter* painter, const QRectF& target = QRectF());

private:
    SudokuCellView** cellViewArray;
    QGraphicsRectItem* theBoxes;
};

#endif // SUDOKUGAMESCENE_H
