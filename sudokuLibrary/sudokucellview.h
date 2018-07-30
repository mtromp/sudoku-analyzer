#ifndef SUDOKUCELLVIEW_H
#define SUDOKUCELLVIEW_H

#include <QObject>
#include <QGraphicsItem>
#include <QLinearGradient>
#include <QPainter>
#include <QRectF>
#include <QWidget>

class SudokuCellView : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    SudokuCellView(void);
//    virtual ~SudokuCellView();

    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

private:
    static QLinearGradient getBackgroundGradient(void);

};

#endif // SUDOKUCELLVIEW_H
