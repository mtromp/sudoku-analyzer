#include "sudokucolumn.h"
#include "sudokucell.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

using namespace testing;

TEST(IntegrateCellColumn, CellSetValueChangesColumnFixedValues)
{
    std::vector<SudokuCell*> nineCells;
    for (int i = 0; i < 9; i++)
    {
        SudokuCell* cell = new SudokuCell;
        nineCells.push_back(&(*cell));
    }
    SudokuColumn column(nineCells);
    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        SudokuCell* cell = (reinterpret_cast<SudokuCell*>(*it));
        QObject::connect(cell, SIGNAL(CellValueSet(int)), &column, SLOT(CellValueSet(int)));
    }

    SudokuCell* cell = nineCells[5];
    cell->SetValue(3);
    std::vector<int> expectedVector = {3};
    EXPECT_EQ(expectedVector, column.FixedValues());

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        SudokuCell* cell = (reinterpret_cast<SudokuCell*>(*it));
        delete cell;
    }
}
