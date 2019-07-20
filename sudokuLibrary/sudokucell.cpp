#include "sudokucell.h"

SudokuCell::SudokuCell()
{
    this->availableValues = {{true,true,true,true,true,true,true,true,true,true}};
}

std::vector<unsigned int> SudokuCell::AvailableValues()
{
    std::vector<unsigned int> valueVector;
    for (unsigned int i = 1; i < 10; i++)
    {
        if (this->availableValues[i])
        {
            valueVector.push_back(i);
        }
    }
    return valueVector;
}

int SudokuCell::DisableValue(const unsigned int value)
{
    this->availableValues[value] = false;
    if (this->AvailableValues().size() == 0)
    {
        this->availableValues[value] = true;
        return -1;
    }
    emit CellValueDisabled(value);
    return 0;
}

int SudokuCell::SetValue(const unsigned int value)
{
    if (!this->availableValues[value]){
        return -1;
    }
    for (unsigned int i = 1; i < 10; i++)
    {
        if (i == value)
        {
            this->availableValues[i] = true;
        } else {
            this->availableValues[i] = false;
        }
    }
    emit CellValueSet(value);
    return 0;
}

bool SudokuCell::IsValueActive(const unsigned int value)
{
    return this->availableValues[value];
}
