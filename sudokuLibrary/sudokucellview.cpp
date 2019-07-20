#include "sudokucellview.h"

#include "dimensions.h"

#include <QInputDialog>
#include <QPainter>

SudokuCellView::SudokuCellView(SudokuCell *aCell, QGraphicsItem *parent) : QGraphicsItem(parent)
                                                                         , theValue(0)
                                                                         , theCell(aCell)
{
    this->setToolTip(QString::number(this->theValue));
}

SudokuCellView::~SudokuCellView()
{
    delete theCell;
}

QRectF SudokuCellView::boundingRect() const
{
    return QRectF(0, 0, Dimensions::cellSize, Dimensions::cellSize);
}

void SudokuCellView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    painter->setPen(QPen(QColor(56, 165, 211), 1));
    painter->drawRect(0, 0, Dimensions::cellSize, Dimensions::cellSize);

    QFont font = QFont(painter->font());

    if (this->theValue == 0) {
        font.setPointSize(Dimensions::cellChoiceFontSize);
        painter->setFont(font);

        int spacing = (Dimensions::cellSize - 3 * Dimensions::cellChoiceFontSize) / 4;
        int xoffset = spacing;
        int yoffset = spacing;

        for(unsigned int number = 1; number <= 9; number++)
        {
            painter->setPen(QPen(QColor(3,73,104)));

            if (theCell->IsValueActive(number)) {
                painter->drawText(QRectF(
                                      xoffset,
                                      yoffset,
                                      Dimensions::cellChoiceFontSize,
                                      Dimensions::cellChoiceFontSize),
                                  Qt::AlignCenter | Qt::AlignVCenter,
                                  QString::number(number)
                                  );
            }
            if ( number == 3 || number == 6)
            {
                yoffset = yoffset + Dimensions::cellChoiceFontSize + spacing;
                xoffset = 2;
            } else {
                xoffset = xoffset + Dimensions::cellChoiceFontSize + spacing;
            }
        }
    }
    else {
        font.setPointSize(Dimensions::cellValueFontSize);
        painter->setFont(font);
        painter->setPen(QPen(QColor(203,73,104)));

        painter->drawText(QRectF(
                              0,
                              0,
                              Dimensions::cellSize,
                              Dimensions::cellSize),
                          Qt::AlignCenter | Qt::AlignVCenter,
                          QString::number(this->theValue)
                          );

    }
}
void SudokuCellView::handleMouseEvent()
{

    bool ok;
    int number = QInputDialog::getInt(nullptr
                                             , "Digit"
                                             , "Enter Digit:"
                                             , static_cast<int>(this->theValue)
                                             , 1, 9, 1, &ok);

    if (ok && number != 0)
    {
        if (0 == this->theCell->SetValue(static_cast<unsigned int>(number))) {
            this->theValue = static_cast<unsigned int>(number); //actually set the cell value.
            this->setToolTip(QString::number(number));
        }
    }
}
