#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include <array>
#include <vector>

class SudokuCell
{
public:
    SudokuCell();
    std::vector<int> AvailableValues();
    int DisableValue(int value);
    int SetValue(int value);

private:
    std::array<bool, 10> availableValues;
};

#endif // SUDOKUCELL_H
