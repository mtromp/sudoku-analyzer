#include "sudokucell.h"

SudokuCell::SudokuCell()
{
    this->availableValues = {{true,true,true,true,true,true,true,true,true,true}};
}

std::vector<int> SudokuCell::AvailableValues()
{
    std::vector<int> valueVector;
    for (int i = 1; i <= 10; i++)
    {
        if (this->availableValues[i])
        {
            valueVector.push_back(i);
        }
    }
    return valueVector;
}

int SudokuCell::DisableValue(int value)
{
    this->availableValues[value] = false;
    if (this->AvailableValues().size() == 0)
    {
        this->availableValues[value] = true;
        return -1;
    }
    return 0;
}
