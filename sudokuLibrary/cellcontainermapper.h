#ifndef CELLCONTAINERMAPPER_H
#define CELLCONTAINERMAPPER_H

#include <array>

class CellContainerMapper
{
public:
    CellContainerMapper();
    int GetRow(int cellNumber);
    int GetColumn(int cellNumber);

private:
    std::array<int, 81> rowMapper;
    std::array<int, 81> columnMapper;
    void InitRowMapper();
    void InitColumnMapper();
};

#endif // CELLCONTAINERMAPPER_H
