#ifndef CELLCONTAINERMAPPER_H
#define CELLCONTAINERMAPPER_H

#include <array>

class CellContainerMapper
{
public:
    CellContainerMapper();
    unsigned int GetRow(const unsigned int cellNumber);
    unsigned int GetColumn(const unsigned int cellNumber);
    unsigned int GetBox(const unsigned int cellNumber);

private:
    std::array<unsigned int, 81> rowMapper;
    std::array<unsigned int, 81> columnMapper;
    std::array<unsigned int, 81> boxMapper;
    void InitRowMapper();
    void InitColumnMapper();
    void InitBoxMapper();
};

#endif // CELLCONTAINERMAPPER_H
