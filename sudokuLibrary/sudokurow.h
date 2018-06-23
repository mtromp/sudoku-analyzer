#ifndef SUDOKUROW_H
#define SUDOKUROW_H

#include "sudokucellcontainer.h"

#include <vector>

#include <QObject>

class SudokuCell;

class SudokuRow : public SudokuCellContainer
{
    Q_OBJECT
public:
    explicit SudokuRow(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);
    virtual ~SudokuRow(){}


public slots:

private:

};

#endif // SUDOKUROW_H
