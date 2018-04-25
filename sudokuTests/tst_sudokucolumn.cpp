#include "sudokucolumn.h"
#include "sudokucell.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

using namespace testing;

// A column will be assigned 9 cells, by whom?
// When a cell value is set, it will send a signal to
//   the column so that the column can disable that value
//   in all the other cells in the column.
// When disabling a value in a cell returns an error, then
//   the column will need to ?????
// The column can set the value of a cell when ???

// Test the behavior of a slot by calling it.
// If we want to verify that a signal is emitted, use QSignalSpy.

class MockSudokuCell : public SudokuCell
{
public:
    MOCK_METHOD0(AvailableValues, std::vector<int>());
    MOCK_METHOD1(DisableValue, int(int value));
    MOCK_METHOD1(SetValue, int(int value));
};

TEST(TestSudokuColumn, ColumnSlotDisablesValueInAllOtherCells)
{
    std::vector<SudokuCell*> nineCells;
    for (int i = 0; i < 9; i++)
    {
        MockSudokuCell* cell = new MockSudokuCell;
        nineCells.push_back(&(*cell));
    }

    SudokuColumn column(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)), DisableValue(4)).Times(AtLeast(1));
    }
    column.CellValueSet(4);

}
