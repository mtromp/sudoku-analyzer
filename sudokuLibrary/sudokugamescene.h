#ifndef SUDOKUGAMESCENE_H
#define SUDOKUGAMESCENE_H

#include "sudokucellview.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QSettings>

class SudokuCellView;

class SudokuGameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SudokuGameScene(QAction *mainWindowPauseAction = nullptr);
    virtual ~SudokuGameScene(void);

    void renderBoard(QPainter* painter, const QRectF& target = QRectF());

public slots:
//    void updateSudokuCellView(int x, int y);

private:
//    void updateSudokuCellViewHelper(int x, int y);
    SudokuCellView ** cellViewArray;
    QGraphicsRectItem * theBoxes;
};

#endif // SUDOKUGAMESCENE_H
