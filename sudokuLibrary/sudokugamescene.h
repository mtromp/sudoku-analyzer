#ifndef SUDOKUGAMESCENE_H
#define SUDOKUGAMESCENE_H

#include <QGraphicsScene>

class SudokuGameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SudokuGameScene(QObject* parent = nullptr);
    virtual ~SudokuGameScene();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    void createNineBigBoxes();
    void createEightyOneCells();
};

#endif // SUDOKUGAMESCENE_H
