#ifndef SUDOKUROW_H
#define SUDOKUROW_H

#include <array>
#include <vector>

#include <QObject>

class SudokuCell;

class SudokuRow : public QObject
{
    Q_OBJECT
public:
    explicit SudokuRow(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);

    virtual std::vector<int> FixedValues();

public slots:
    int CellValueSet(int value);

private:
    std::vector<SudokuCell*> cells;
    std::array<bool, 10> fixedValues;
};

#endif // SUDOKUROW_H
