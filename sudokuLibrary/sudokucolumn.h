#ifndef SUDOKUCOLUMN_H
#define SUDOKUCOLUMN_H

#include <QObject>

class SudokuCell;

class SudokuColumn : public QObject
{
    Q_OBJECT
public:
    explicit SudokuColumn(std::vector<SudokuCell*> nineCells, QObject *parent = nullptr);

signals:

public slots:
    void CellValueSet(int Value);

private:
    std::vector<SudokuCell*> cells;
};

#endif // SUDOKUCOLUMN_H
