#ifndef CELLCONTAINERMAPPER_H
#define CELLCONTAINERMAPPER_H

#include <array>

class CellContainerMapper
{
public:
    CellContainerMapper();
    int GetRow(int cellNumber);

private:
    std::array<int, 81> rowMapper;
    void InitRowMapper();
};

#endif // CELLCONTAINERMAPPER_H
