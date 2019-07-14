#include "cellcontainermapper.h"

CellContainerMapper::CellContainerMapper()
{
    InitRowMapper();
}

int CellContainerMapper::GetRow(int cellNumber)
{
    return (rowMapper[cellNumber-1] + 1);
}

void CellContainerMapper::InitRowMapper()
{
    int cellNumber = 0;
    for (int row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            this->rowMapper[cellNumber] = row;
            cellNumber++;
        }
    }
}
