#include "sudokucellcontainer.h"
#include "sudokucell.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <array>
#include <vector>

using namespace testing;

TEST(IntegrateCellContainer, CellSetValueChangesContainerFixedValues)
{
    std::array<SudokuCell*, 9> nineCells;
    for (unsigned int i = 0; i < 9; i++)
    {
        SudokuCell* cell = new SudokuCell;
        nineCells[i] = cell;
    }
    SudokuCellContainer container(nineCells);
    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        SudokuCell* cell = (reinterpret_cast<SudokuCell*>(*it));
        QObject::connect(cell, SIGNAL(CellValueSet(unsigned int)), &container, SLOT(CellValueSet(unsigned int)));
    }

    SudokuCell* cell = nineCells[5];
    cell->SetValue(3);
    std::vector<unsigned int> expectedVector = {3};
    EXPECT_EQ(expectedVector, container.FixedValues());

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        SudokuCell* cell = (reinterpret_cast<SudokuCell*>(*it));
        delete cell;
    }
}
