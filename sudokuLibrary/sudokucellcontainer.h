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
    explicit SudokuCellContainer(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);
    virtual ~SudokuCellContainer(){}

    virtual std::vector<int> FixedValues();
signals:

public slots:
    int CellValueSet(int value);

private:
    std::vector<SudokuCell*> cells;
    std::array<bool, 10> fixedValues;
};

#endif // SUDOKUCELLCONTAINER_H
