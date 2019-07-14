#include "cellcontainermapper.h"

#include <gtest/gtest.h>

using namespace testing;

class CellContainerMapperTest : public Test
{
    protected:
        CellContainerMapper mapper;
};

TEST_F(CellContainerMapperTest, GetRowReturnsOneForCellNine)
{
    EXPECT_EQ(1, mapper.GetRow(9));
}

TEST_F(CellContainerMapperTest, GetRowReturnsNineForCellEightyOne)
{
    EXPECT_EQ(9, mapper.GetRow(81));
}

TEST_F(CellContainerMapperTest, GetRowReturnsFourForCellThirtySix)
{
    EXPECT_EQ(4, mapper.GetRow(36));
}

TEST_F(CellContainerMapperTest, GetColumnReturnsOneForCellTen)
{
    EXPECT_EQ(1, mapper.GetColumn(10));
}

TEST_F(CellContainerMapperTest, GetColumnReturnsNineForCellEightyOne)
{
    EXPECT_EQ(9, mapper.GetColumn(81));
}

TEST_F(CellContainerMapperTest, GetColumnReturnsFiveForCellThirtyTwo)
{
    EXPECT_EQ(5, mapper.GetColumn(32));
}

TEST_F(CellContainerMapperTest, GetBoxReturnsOneForCellTen)
{
    EXPECT_EQ(1, mapper.GetBox(10));
}
TEST_F(CellContainerMapperTest, GetBoxReturnsNineForCellSixtyThree)
{
    EXPECT_EQ(9, mapper.GetBox(63));
}
TEST_F(CellContainerMapperTest, GetBoxReturnsSixForCellThirtySix)
{
    EXPECT_EQ(6, mapper.GetBox(36));
}
