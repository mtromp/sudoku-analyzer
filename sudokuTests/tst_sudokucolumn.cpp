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
    virtual ~MockSudokuCell(){}
};

class SudokuColumnTest : public Test
{
protected:
    SudokuColumnTest()
    {
        for (int i = 0; i < 9; i++)
        {
            MockSudokuCell* cell = new MockSudokuCell;
            nineCells.push_back(&(*cell));
        }
    }
    ~SudokuColumnTest()
    {
        for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
        {
            MockSudokuCell* cell = (reinterpret_cast<MockSudokuCell*>(*it));
            delete cell;
        }
    }
    std::vector<SudokuCell*> nineCells;
};

TEST_F(SudokuColumnTest, ColumnCellValueSetDisablesValueInAllCells)
{
    SudokuColumn column(nineCells);
    int valueToDisable = 4;

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)), DisableValue(valueToDisable)).Times(AtLeast(1));
    }
    column.CellValueSet(valueToDisable);
}

TEST_F(SudokuColumnTest, ColumnCellValueSetCapturesColumnFixedValues)
{
    int expectedColumnFixedValue = 5;
    std::vector<int> expectedVector = {expectedColumnFixedValue};

    SudokuColumn column(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                      DisableValue(expectedColumnFixedValue)).Times(AtLeast(1));
    }
    column.CellValueSet(expectedColumnFixedValue);

    EXPECT_EQ(expectedVector, column.FixedValues());
}

TEST_F(SudokuColumnTest, ColumnCellValueSetDoesNotCallDisableValueWhenAlreadyFixed)
{
    int expectedColumnFixedValue = 5;

    SudokuColumn column(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                      DisableValue(expectedColumnFixedValue)).Times(1);
    }
    column.CellValueSet(expectedColumnFixedValue);
    column.CellValueSet(expectedColumnFixedValue);
}

TEST_F(SudokuColumnTest, FixedValueNotSetIfCellReturnsDisableValueError)
{
    int willNotSetValue = 5;
    std::vector<int> expectedVector = {};
    SudokuColumn column(nineCells);

    int iteratorCount = 0;
    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        if (willNotSetValue == iteratorCount)
        {
            EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                        DisableValue(willNotSetValue)).Times(AtLeast(1))
                    .WillRepeatedly(Return(-1));

        } else {
            EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                        DisableValue(willNotSetValue)).Times(AtLeast(1));
        }
        iteratorCount++;
    }
    column.CellValueSet(willNotSetValue);


    EXPECT_EQ(expectedVector, column.FixedValues());
}

TEST_F(SudokuColumnTest, CellSetValueReturnsErrorIfCellReturnsDisableValueError)
{
    int willNotSetValue = 5;
    std::vector<int> expectedVector = {};
    SudokuColumn column(nineCells);

    int iteratorCount = 0;
    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        if (willNotSetValue == iteratorCount)
        {
            EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                        DisableValue(willNotSetValue)).Times(AtLeast(1))
                    .WillRepeatedly(Return(-1));

        } else {
            EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                        DisableValue(willNotSetValue)).Times(AtLeast(1));
        }
        iteratorCount++;
    }
    EXPECT_EQ(-1, column.CellValueSet(willNotSetValue));

}
