#ifndef SUDOKUCOLUMN_H
#define SUDOKUCOLUMN_H

#include "sudokucellcontainer.h"

#include <vector>

#include <QObject>

class SudokuCell;

class SudokuColumn : public SudokuCellContainer
{
    Q_OBJECT
public:
    explicit SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);
    virtual ~SudokuColumn(){}

signals:

public slots:

};

#endif // SUDOKUCOLUMN_H
