#include "sudokucell.h"

#include <QSignalSpy>

#include <vector>
#include <gtest/gtest.h>

using namespace testing;

class SudokuCellTest : public Test
{
protected:
    SudokuCellTest() : cell(){}
    ~SudokuCellTest() {}

    SudokuCell cell;
};

TEST_F(SudokuCellTest, SudokuCellReturnsAvailableValues)
{
    std::vector<int> expectedArray = {1,2,3,4,5,6,7,8,9};

    EXPECT_EQ(expectedArray, cell.AvailableValues());
}

TEST_F(SudokuCellTest, DisablingAValueRemovesItFromTheAvailableValuesList)
{
    std::vector<int> expectedArray = {1,2,3,5,6,7,8,9};

    cell.DisableValue(4);

    EXPECT_EQ(expectedArray, cell.AvailableValues());
}

TEST_F(SudokuCellTest, DisablingTheLastValueFromACellReturnsAnError)
{
    for (int i = 1; i < 9; i++)
    {
        EXPECT_EQ(0, cell.DisableValue(i));
    }
    EXPECT_EQ(-1, cell.DisableValue(9));
}

TEST_F(SudokuCellTest, DisablingTheLastValueFromACellRetainsValueAsAvailable)
{
    std::vector<int> expectedVector = {9};
    for (int i = 1; i < 9; i++)
    {
        EXPECT_EQ(0, cell.DisableValue(i));
    }
    EXPECT_EQ(-1, cell.DisableValue(9));
    EXPECT_EQ(expectedVector, cell.AvailableValues());
}

TEST_F(SudokuCellTest, SettingAValueReturnsOneAvailableValue)
{
    std::vector<int> expectedVector = {4};
    EXPECT_EQ(0, cell.SetValue(4));

    EXPECT_EQ(expectedVector, cell.AvailableValues());
}

TEST_F(SudokuCellTest, SettingAValueGeneratesCellValueSetSignal)
{
    QSignalSpy spy(&cell, SIGNAL(CellValueSet(int)));
    int ExpectedSetValue = 5;
    cell.SetValue(ExpectedSetValue);
    EXPECT_EQ(1, spy.count());
    QList<QVariant> arguments = spy.takeFirst();
    EXPECT_EQ(ExpectedSetValue, arguments.at(0).toInt());
}

TEST_F(SudokuCellTest, AttemptingToSetDisabledValueReturnsError)
{
    cell.DisableValue(4);
    EXPECT_EQ(-1, cell.SetValue(4));
}

TEST_F(SudokuCellTest, DisablingValueGeneratesCellValueDisabledSignal)
{
    QSignalSpy spy(&cell, SIGNAL(CellValueDisabled(int)));
    int ExpectedDisableValue = 4;
    cell.DisableValue(ExpectedDisableValue);
    EXPECT_EQ(1, spy.count());
    QList<QVariant> arguments = spy.takeFirst();
    EXPECT_EQ(ExpectedDisableValue, arguments.at(0).toInt());
}

TEST_F(SudokuCellTest, QueryOfADisabledValueReturnsFalse)
{
    int disabledValue = 4;
    cell.DisableValue(disabledValue);
    EXPECT_FALSE(cell.IsValueActive(disabledValue));
}

TEST_F(SudokuCellTest, QueryOfAnEnabledValueReturnsTrue)
{
    EXPECT_TRUE(cell.IsValueActive(9));
}
