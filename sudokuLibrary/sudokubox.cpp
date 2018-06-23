#include "sudokubox.h"
#include "sudokucell.h"

SudokuBox::SudokuBox(std::vector<SudokuCell *> nineCells, QObject *parent)
    : SudokuCellContainer(nineCells, parent)
{
}
