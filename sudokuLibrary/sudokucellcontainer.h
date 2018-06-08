#ifndef SUDOKUCELLCONTAINER_H
#define SUDOKUCELLCONTAINER_H

#include <QObject>

class SudokuCellContainer : public QObject
{
    Q_OBJECT
public:
    explicit SudokuCellContainer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SUDOKUCELLCONTAINER_H