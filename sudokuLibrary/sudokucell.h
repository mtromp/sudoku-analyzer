#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include <array>
#include <vector>

#include <QObject>

class SudokuCell : public QObject
{
    Q_OBJECT

public:
    SudokuCell();
    virtual ~SudokuCell(){}
    virtual std::vector<int> AvailableValues();
    virtual int DisableValue(int value);
    virtual int SetValue(int value);

signals:
    void CellValueDisabled(int value);
    void CellValueSet(int value);

private:
    std::array<bool, 10> availableValues;
};

#endif // SUDOKUCELL_H
