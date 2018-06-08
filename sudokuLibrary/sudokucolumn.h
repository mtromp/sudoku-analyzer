#ifndef SUDOKUCOLUMN_H
#define SUDOKUCOLUMN_H

#include <array>
#include <vector>

#include <QObject>

class SudokuCell;

class SudokuColumn : public QObject
{
    Q_OBJECT
public:
    explicit SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);

    virtual std::vector<int> FixedValues();
signals:

public slots:
    void CellValueSet(int Value);

private:
    std::vector<SudokuCell*> cells;
    std::array<bool, 10> fixedValues;
};

#endif // SUDOKUCOLUMN_H
