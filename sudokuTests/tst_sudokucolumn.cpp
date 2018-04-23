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
    MockSudokuCell cell1;
    MockSudokuCell cell2;
    MockSudokuCell cell3;
    MockSudokuCell cell4;
    MockSudokuCell cell5;
    MockSudokuCell cell6;
    MockSudokuCell cell7;
    MockSudokuCell cell8;
    MockSudokuCell cell9;
    nineCells.push_back(&cell1);
    nineCells.push_back(&cell2);
    nineCells.push_back(&cell3);
    nineCells.push_back(&cell4);
    nineCells.push_back(&cell5);
    nineCells.push_back(&cell6);
    nineCells.push_back(&cell7);
    nineCells.push_back(&cell8);
    nineCells.push_back(&cell9);

    SudokuColumn column(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)), DisableValue(4)).Times(AtLeast(1));
    }
    column.CellValueSet(4);

}
