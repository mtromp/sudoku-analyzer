#include "sudokurow.h"
#include "sudokucell.h"

SudokuRow::SudokuRow(std::vector<SudokuCell*> nineCells, QObject *parent)
    : SudokuCellContainer(nineCells, parent)
{
}
