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

TEST_F(SudokuRowTest, RowCellValueSetCapturesRowFixedValues)
{
    int expectedRowFixedValue = 5;
    std::vector<int> expectedVector = {expectedRowFixedValue};

    SudokuRow row(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                      DisableValue(expectedRowFixedValue)).Times(AtLeast(1));
    }
    row.CellValueSet(expectedRowFixedValue);

    EXPECT_EQ(expectedVector, row.FixedValues());
}

TEST_F(SudokuRowTest, RowCellValueSetDoesNotCallDisableValueWhenAlreadyFixed)
{
    int expectedRowFixedValue = 5;

    SudokuRow row(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                      DisableValue(expectedRowFixedValue)).Times(1);
    }
    row.CellValueSet(expectedRowFixedValue);
    row.CellValueSet(expectedRowFixedValue);
}

TEST_F(SudokuRowTest, FixedValueNotSetIfCellReturnsDisableValueError)
{
    int willNotSetValue = 5;
    std::vector<int> expectedVector = {};
    SudokuRow row(nineCells);

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
    row.CellValueSet(willNotSetValue);


    EXPECT_EQ(expectedVector, row.FixedValues());
}

TEST_F(SudokuRowTest, CellSetValueReturnsErrorIfCellReturnsDisableValueError)
{
    int willNotSetValue = 5;

    SudokuRow row(nineCells);

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
    EXPECT_EQ(-1, row.CellValueSet(willNotSetValue));

}

