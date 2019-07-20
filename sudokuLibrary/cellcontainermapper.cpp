#include "cellcontainermapper.h"

CellContainerMapper::CellContainerMapper()
{
    InitRowMapper();
    InitColumnMapper();
    InitBoxMapper();
}

unsigned int CellContainerMapper::GetRow(const unsigned int cellNumber)
{
    return (rowMapper[cellNumber-1] + 1);
}

unsigned int CellContainerMapper::GetColumn(const unsigned int cellNumber)
{
    return (columnMapper[cellNumber-1] + 1);
}

unsigned int CellContainerMapper::GetBox(const unsigned int cellNumber)
{
    return (boxMapper[cellNumber-1] + 1);
}

void CellContainerMapper::InitRowMapper()
{
    unsigned int cellNumber = 0;
    for (unsigned int row = 0; row < 9; ++row)
    {
        for (unsigned int column = 0; column < 9; ++column)
        {
            this->rowMapper[cellNumber] = row;
            cellNumber++;
        }
    }
}

void CellContainerMapper::InitColumnMapper()
{
    unsigned int cellNumber = 0;
    for (unsigned int row = 0; row < 9; ++row)
    {
        for (unsigned int column = 0; column < 9; ++column)
        {
            this->columnMapper[cellNumber] = column;
            cellNumber++;
        }
    }
}
void CellContainerMapper::InitBoxMapper()
{
    unsigned int cellNumber = 0;
    unsigned int boxNumber = 0;
    for (unsigned int row = 0; row < 9; ++row)
    {
        for (unsigned int column = 0; column < 9; ++column)
        {
            boxNumber = ((row / 3)*3) + (column / 3);
            this->boxMapper[cellNumber] = boxNumber;
            cellNumber++;
        }
    }

}
