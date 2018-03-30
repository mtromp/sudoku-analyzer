#include "sudokucell.h"

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
    EXPECT_EQ(0, cell.DisableValue(1));
    EXPECT_EQ(0, cell.DisableValue(2));
    EXPECT_EQ(0, cell.DisableValue(3));
    EXPECT_EQ(0, cell.DisableValue(4));
    EXPECT_EQ(0, cell.DisableValue(5));
    EXPECT_EQ(0, cell.DisableValue(6));
    EXPECT_EQ(0, cell.DisableValue(7));
    EXPECT_EQ(0, cell.DisableValue(8));
    EXPECT_EQ(-1, cell.DisableValue(9));
}
TEST(TestSudokuCell, DisablingTheLastValueFromACellRetainsValueAsAvailable)
{
    SudokuCell cell;
    std::vector<int> expectedVector = {9};
    EXPECT_EQ(0, cell.DisableValue(1));
    EXPECT_EQ(0, cell.DisableValue(2));
    EXPECT_EQ(0, cell.DisableValue(3));
    EXPECT_EQ(0, cell.DisableValue(4));
    EXPECT_EQ(0, cell.DisableValue(5));
    EXPECT_EQ(0, cell.DisableValue(6));
    EXPECT_EQ(0, cell.DisableValue(7));
    EXPECT_EQ(0, cell.DisableValue(8));
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
