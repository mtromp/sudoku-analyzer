#ifndef SUDOKUGAMESCENE_H
#define SUDOKUGAMESCENE_H

#include "sudokucellcontainer.h"
#include "cellcontainermapper.h"
#include <QGraphicsScene>
#include <QObject>

#include <array>

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
    void createCellContainers();

    void addCellToBoxes(SudokuCell* theCell, int cellNumber);

    CellContainerMapper mapper;
    std::array<SudokuCellContainer*, 9> sudokuRows;
    std::array<SudokuCellContainer*, 9> sudokuColumns;
    std::array<SudokuCellContainer*, 9> sudokuBoxes;
};

#endif // SUDOKUGAMESCENE_H
