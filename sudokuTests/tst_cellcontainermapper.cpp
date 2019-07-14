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
