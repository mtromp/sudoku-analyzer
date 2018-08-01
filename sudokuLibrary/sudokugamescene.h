#ifndef SUDOKUGAMESCENE_H
#define SUDOKUGAMESCENE_H

#include <QGraphicsScene>

class SudokuGameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SudokuGameScene(QObject* parent = nullptr);
    virtual ~SudokuGameScene();

};

#endif // SUDOKUGAMESCENE_H
