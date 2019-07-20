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
    virtual std::vector<unsigned int> AvailableValues();
    virtual int DisableValue(const unsigned int value);
    virtual int SetValue(const unsigned int value);
    virtual bool IsValueActive(const unsigned int value);

signals:
    void CellValueDisabled(unsigned int value);
    void CellValueSet(unsigned int value);

private:
    std::array<bool, 10> availableValues;
};

#endif // SUDOKUCELL_H
