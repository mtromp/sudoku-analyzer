#include "cellcontainermapper.h"

CellContainerMapper::CellContainerMapper()
{
    InitRowMapper();
    InitColumnMapper();
    InitBoxMapper();
}

int CellContainerMapper::GetRow(int cellNumber)
{
    return (rowMapper[cellNumber-1] + 1);
}

int CellContainerMapper::GetColumn(int cellNumber)
{
    return (columnMapper[cellNumber-1] + 1);
}

int CellContainerMapper::GetBox(int cellNumber)
{
    return (boxMapper[cellNumber-1] + 1);
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

void CellContainerMapper::InitColumnMapper()
{
    int cellNumber = 0;
    for (int row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            this->columnMapper[cellNumber] = column;
            cellNumber++;
        }
    }
}
void CellContainerMapper::InitBoxMapper()
{
    int cellNumber = 0;
    int boxNumber = 0;
    for (int row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            boxNumber = ((row / 3)*3) + (column / 3);
            this->boxMapper[cellNumber] = boxNumber;
            cellNumber++;
        }
    }

}
