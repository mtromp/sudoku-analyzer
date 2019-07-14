#ifndef SUDOKUCELLCONTAINER_H
#define SUDOKUCELLCONTAINER_H

#include <array>
#include <vector>

#include <QObject>

class SudokuCell;

class SudokuCellContainer : public QObject
{
    Q_OBJECT
public:
    explicit SudokuCellContainer(std::array<SudokuCell*, 9> nineCells, QObject *parent = nullptr);
    SudokuCellContainer(QObject *parent = nullptr);

    virtual ~SudokuCellContainer(){}

    void AddCell(SudokuCell* theCell);

    virtual std::vector<int> FixedValues();
signals:

public slots:
    int CellValueSet(int value);

private:
    int nextCellPosition;
    std::array<SudokuCell*, 9> cells;
    std::array<bool, 10> fixedValues;
};

#endif // SUDOKUCELLCONTAINER_H
