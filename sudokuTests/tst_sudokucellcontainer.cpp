#include "sudokucellcontainer.h"
#include "sudokucell.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <array>
#include <vector>

using namespace testing;

// A cell container will be assigned 9 cells.
// When a cell value is set, it will send a signal
//   to the container so that the container can
//   disable that value in the other cells in
//   that container.

class MockSudokuCell : public SudokuCell
{
public:
    MOCK_METHOD0(AvailableValues, std::vector<int>());
    MOCK_METHOD1(DisableValue, int(int value));
    MOCK_METHOD1(SetValue, int(int value));
    virtual ~MockSudokuCell(){}
};

class SudokuCellContainerTest : public Test
{
protected:
    SudokuCellContainerTest()
    {
        for (int i = 0; i < 9; i++)
        {
            MockSudokuCell* cell = new MockSudokuCell;
            nineCells[i] = cell;
        }
    }
    ~SudokuCellContainerTest()
    {
        for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
        {
            MockSudokuCell* cell = (reinterpret_cast<MockSudokuCell*>(*it));
            delete cell;
        }
    }
    std::array<SudokuCell*, 9> nineCells;
};

TEST_F(SudokuCellContainerTest, ContainerCellValueSetDisablesValueInAllCells)
{
    SudokuCellContainer container(nineCells);
    int valueToDisable = 4;

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)), DisableValue(valueToDisable)).Times(AtLeast(1));
    }
    container.CellValueSet(valueToDisable);
}

TEST_F(SudokuCellContainerTest, ContainerCellValueSetCapturesColumnFixedValues)
{
    int expectedContainerFixedValue = 5;
    std::vector<int> expectedVector = {expectedContainerFixedValue};

    SudokuCellContainer container(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                      DisableValue(expectedContainerFixedValue)).Times(AtLeast(1));
    }
    container.CellValueSet(expectedContainerFixedValue);

    EXPECT_EQ(expectedVector, container.FixedValues());
}

TEST_F(SudokuCellContainerTest, ContainerCellValueSetDoesNotCallDisableValueWhenAlreadyFixed)
{
    int expectedContainerFixedValue = 5;

    SudokuCellContainer container(nineCells);

    for (auto it = nineCells.begin(); it != nineCells.end(); ++it)
    {
        EXPECT_CALL(*(reinterpret_cast<MockSudokuCell*>(*it)),
                      DisableValue(expectedContainerFixedValue)).Times(1);
    }
    container.CellValueSet(expectedContainerFixedValue);
    container.CellValueSet(expectedContainerFixedValue);
}

TEST_F(SudokuCellContainerTest, FixedValueNotSetIfCellReturnsDisableValueError)
{
    int willNotSetValue = 5;
    std::vector<int> expectedVector = {};
    SudokuCellContainer container(nineCells);

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
    container.CellValueSet(willNotSetValue);


    EXPECT_EQ(expectedVector, container.FixedValues());
}

TEST_F(SudokuCellContainerTest, CellSetValueReturnsErrorIfCellReturnsDisableValueError)
{
    int willNotSetValue = 5;

    SudokuCellContainer container(nineCells);

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
    EXPECT_EQ(-1, container.CellValueSet(willNotSetValue));

}
