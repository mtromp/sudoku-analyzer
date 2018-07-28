#ifndef SUDOKUCELLVIEW_H
#define SUDOKUCELLVIEW_H

#include <QObject>

class SudokuCellView : public QObject
{
    Q_OBJECT
public:
    explicit SudokuCellView(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SUDOKUCELLVIEW_H