#include "sudokucolumn.h"
#include "sudokucell.h"

SudokuColumn::SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent) : QObject(parent)
{
    this->cells = nineCells;
    this->fixedValues = {{false,false,false,false,false,false,false,false,false,false}};
}

void SudokuColumn::CellValueSet(int value)
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
}

std::vector<int> SudokuColumn::FixedValues()
{
    std::vector<int> fixedVector;
    for (int i = 1; i < 10; i++)
    {
        if (this->fixedValues[i])
        {
            fixedVector.push_back(i);
        }
    }

    return fixedVector;
}

