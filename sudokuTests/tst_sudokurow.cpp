#include "sudokurow.h"
#include "sudokucell.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

using namespace testing;

class MockSudokuCell : public SudokuCell
{
public:
    MOCK_METHOD0(AvailableValues, std::vector<int>());
    MOCK_METHOD1(DisableValue, int(int value));
    MOCK_METHOD1(SetValue, int(int value));
    virtual ~MockSudokuCell(){}
};

class SudokuRowTest : public Test
{
protected:
    SudokuRowTest()
    {
        for (int i = 0; i < 9; i++)
        {
            MockSudokuCell* cell = new MockSudokuCell;
            nineCells.push_back(&(*cell));
        }
    }
    ~SudokuRowTest()
    {
        for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
        {
            MockSudokuCell* cell = (reinterpret_cast<MockSudokuCell*>(*it));
            delete cell;
        }
    }
    std::vector<SudokuCell*> nineCells;
};

TEST_F(SudokuRowTest, RowCellValueSetDisablesValueInAllCells)
{
    SudokuRow row(nineCells);
    int valueToDisable = 4;

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)), DisableValue(valueToDisable)).Times(AtLeast(1));
    }
    row.CellValueSet(valueToDisable);
}

