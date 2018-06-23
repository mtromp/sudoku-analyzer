#ifndef SUDOKUBOX_H
#define SUDOKUBOX_H

#include "sudokucellcontainer.h"

#include <vector>

#include <QObject>

class SudokuBox : public SudokuCellContainer
{
    Q_OBJECT
public:
    explicit SudokuBox(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);
    virtual ~SudokuBox(){}

public slots:

};

#endif // SUDOKUBOX_H
