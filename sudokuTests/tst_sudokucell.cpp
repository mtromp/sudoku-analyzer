#include "sudokucell.h"

#include <QSignalSpy>

#include <vector>
#include <gtest/gtest.h>

using namespace testing;

TEST(TestSudokuCell, SudokuCellReturnsAvailableValues)
{
    SudokuCell cell;
    std::vector<int> expectedArray = {1,2,3,4,5,6,7,8,9};

    EXPECT_EQ(expectedArray, cell.AvailableValues());
}

TEST(TestSudokuCell, DisablingAValueRemovesItFromTheAvailableValuesList)
{
    SudokuCell cell;
    std::vector<int> expectedArray = {1,2,3,5,6,7,8,9};

    cell.DisableValue(4);

    EXPECT_EQ(expectedArray, cell.AvailableValues());
}

TEST(TestSudokuCell, DisablingTheLastValueFromACellReturnsAnError)
{
    SudokuCell cell;
    for (int i = 1; i < 9; i++)
    {
        EXPECT_EQ(0, cell.DisableValue(i));
    }
    EXPECT_EQ(-1, cell.DisableValue(9));
}
TEST(TestSudokuCell, DisablingTheLastValueFromACellRetainsValueAsAvailable)
{
    SudokuCell cell;
    std::vector<int> expectedVector = {9};
    for (int i = 1; i < 9; i++)
    {
        EXPECT_EQ(0, cell.DisableValue(i));
    }
    EXPECT_EQ(-1, cell.DisableValue(9));
    EXPECT_EQ(expectedVector, cell.AvailableValues());
}

TEST(TestSudokuCell, SettingAValueReturnsOneAvailableValue)
{
    SudokuCell cell;
    std::vector<int> expectedVector = {4};
    EXPECT_EQ(0, cell.SetValue(4));

    EXPECT_EQ(expectedVector, cell.AvailableValues());
}

TEST(TestSudokuCell, AttemptingToSetDisabledValueReturnsError)
{
    SudokuCell cell;
    cell.DisableValue(4);
    EXPECT_EQ(-1, cell.SetValue(4));
}

TEST(TestSudokuCell, DisablingValueGeneratesCellChangedSignal)
{
    SudokuCell cell;
    QSignalSpy spy(&cell, SIGNAL(CellChanged(int)));
    int ExpectedDisableValue = 4;
    cell.DisableValue(ExpectedDisableValue);
    EXPECT_EQ(1, spy.count());
    QList<QVariant> arguments = spy.takeFirst();
    EXPECT_EQ(ExpectedDisableValue, arguments.at(0).toInt());
}
