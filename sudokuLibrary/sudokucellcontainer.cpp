#include "sudokucellcontainer.h"
#include "sudokucell.h"

SudokuCellContainer::SudokuCellContainer(std::vector<SudokuCell*> nineCells, QObject *parent) : QObject(parent)
{
    this->cells = nineCells;
    this->fixedValues = {{false,false,false,false,false,false,false,false,false,false}};
}

int SudokuCellContainer::CellValueSet(int value)
{
    int retVal = 0;
    QObject* signalingObject = this->sender();
    if (!this->fixedValues[value])
    {
        for (auto it = this->cells.begin(); it != this->cells.end(); ++it)
        {
            SudokuCell* cell = reinterpret_cast<SudokuCell*>(*it);
            if (cell == signalingObject)
            {
                continue;
            }
            if (0 != cell->DisableValue(value))
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

std::vector<int> SudokuCellContainer::FixedValues()
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
