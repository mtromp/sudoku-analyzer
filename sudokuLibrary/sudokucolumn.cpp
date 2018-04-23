#include "sudokucolumn.h"
#include "sudokucell.h"

SudokuColumn::SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent) : QObject(parent)
{
    this->cells = nineCells;
}

void SudokuColumn::CellValueSet(int Value)
{
    for (auto it = this->cells.begin(); it != this->cells.end(); ++it)
    {
        reinterpret_cast<SudokuCell*>(*it)->DisableValue(Value);
    }
}
