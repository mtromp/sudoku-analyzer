#include "sudokucolumn.h"
#include "sudokucell.h"

SudokuColumn::SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent)
    : SudokuCellContainer(nineCells, parent)
{
}
