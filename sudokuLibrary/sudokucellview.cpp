#include "sudokucellview.h"

#include "dimensions.h"

#include <QPainter>

SudokuCellView::SudokuCellView()
{

}
SudokuCellView::~SudokuCellView()
{

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
    font.setPixelSize(Dimensions::cellChoiceFontSize);
    painter->setFont(font);

    int spacing = (Dimensions::cellSize - 3 * Dimensions::cellChoiceFontSize) / 4;
    int xoffset = spacing;
    int yoffset = spacing;

    for(int number = 1; number <= 9; number++)
    {
        painter->setPen(QPen(QColor(3,73,104)));

        painter->drawText(QRectF(
                                 xoffset,
                                 yoffset,
                                 Dimensions::cellChoiceFontSize,
                                 Dimensions::cellChoiceFontSize),
                          Qt::AlignCenter | Qt::AlignVCenter,
                          QString::number(number)
                    );
        if ( number == 3 || number == 6)
        {
            yoffset = yoffset + Dimensions::cellChoiceFontSize + spacing;
            xoffset = 2;
        } else {
            xoffset = xoffset + Dimensions::cellChoiceFontSize + spacing;
        }
    }

}
