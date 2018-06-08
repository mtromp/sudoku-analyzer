#include "sudokucolumn.h"
#include "sudokucell.h"

SudokuColumn::SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent) : QObject(parent)
{
    this->cells = nineCells;
    this->fixedValues = {{false,false,false,false,false,false,false,false,false,false}};
}

void SudokuColumn::CellValueSet(int value)
{

    if (!this->fixedValues[value])
    {
        for (auto it = this->cells.begin(); it != this->cells.end(); ++it)
        {
            reinterpret_cast<SudokuCell*>(*it)->DisableValue(value);
        }
        this->fixedValues[value] = true;
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

