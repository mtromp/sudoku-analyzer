#include "sudokurow.h"
#include "sudokucell.h"

SudokuRow::SudokuRow(std::vector<SudokuCell*> nineCells, QObject *parent) : QObject(parent)
{
    this->cells = nineCells;
    this->fixedValues = {{false,false,false,false,false,false,false,false,false,false}};
}

int SudokuRow::CellValueSet(int value)
{
    int retVal = 0;
    if (!this->fixedValues[value])
    {
        for (auto it = this->cells.begin(); it != this->cells.end(); ++it)
        {
            if (0 != reinterpret_cast<SudokuCell*>(*it)->DisableValue(value))
            {
                retVal = -1;
            };
        }
        if (0 == retVal)
        {
            this->fixedValues[value] = true;
        }
    }
    return retVal;
}
