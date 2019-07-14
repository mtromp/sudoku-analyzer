#ifndef CELLCONTAINERMAPPER_H
#define CELLCONTAINERMAPPER_H

#include <array>

class CellContainerMapper
{
public:
    CellContainerMapper();
    int GetRow(int cellNumber);
    int GetColumn(int cellNumber);
    int GetBox(int cellNumber);

private:
    std::array<int, 81> rowMapper;
    std::array<int, 81> columnMapper;
    std::array<int, 81> boxMapper;
    void InitRowMapper();
    void InitColumnMapper();
    void InitBoxMapper();
};

#endif // CELLCONTAINERMAPPER_H
