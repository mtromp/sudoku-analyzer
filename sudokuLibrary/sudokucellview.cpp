#include "sudokucellview.h"

SudokuCellView::SudokuCellView(void)
{
    m_x = -1;
    m_y = -1;
    m_focus = false;
    m_generated = false;

    setAcceptHoverEvents(false);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF SudokuCellView::boundingRect(void) const {
    return QRectF(0, 0, Dimensions::elementSize, Dimensions::elementSize);
}

void SudokuCellView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    // Use a gradient for the brush.
    QLinearGradient gradient = SudokuCellView::getBackgroundGradient();
    gradient.setColorAt(0, QColor(170, 218, 238));
    gradient.setColorAt(1, QColor(223, 243, 252));
    painter->setBrush(gradient);

    // Draw the box.
    painter->setPen(QPen(QColor(56, 165, 211), 1));
    painter->drawRect(0, 0, Dimensions::elementSize, Dimensions::elementSize);
    QFont font = QFont(painter->font());
    font.setPixelSize(Dimensions::elementChoiceSize);
    painter->setFont(font);

    for (int number = 1; number <= 9; number++) {
        // When chosen: dark blue pen, light blue-ish otherwise.
        painter->setPen(QPen(QColor(87, 106, 114), 0));

        // When chosen: bold font.
        QFont font = QFont(painter->font());
        font.setBold(false);
        painter->setFont(font);

        // Draw!
        painter->drawText(
            getBoundingRectForChoice(number),
            Qt::AlignCenter | Qt::AlignVCenter,
            QString::number(number)
        );
    }


}
/**
 * Get the background gradient, without the colors set. This allows us to
 * generate the gradient only *once*!
 *
 * @return
 *   A gradient object for which only the colors still have to be set.
 */
QLinearGradient SudokuCellView::getBackgroundGradient(void) {
    static bool generated = false;
    static QLinearGradient gradient;

    if (!generated) {
        double start = (double) Dimensions::elementSize / 6;
        double end = (double) Dimensions::elementSize * 5 / 6;
        gradient = QLinearGradient(QPointF(start, start), QPointF(end, end));

        generated = true;
    }

    return gradient;
}

/**
 * Get the bounding rectangle for a number, and determine the number by its
 * position in the SudokuElement ((x, y) coordinates, where x, y = {0, 1, 2}).
 *
 * @param x
 *   x coordinate of a number in the SudokuElement
 * @param y
 *   y coordinate of a number in the SudokuElement
 * @return
 *   A bounding rectangle
 */
QRect SudokuCellView::getBoundingRectForChoiceByCoords(int x, int y) const {
    if (x < 0 || x > 2 || y < 0 || y > 2)
        qFatal("SudokuElement::getBoundingRectForChoiceByCoords(): x or y was not in the valid range (0-2). x: %d, y: %d.", x, y);

    int offset = (Dimensions::elementSize - (3 * Dimensions::elementChoiceSize)) / 4;
    int nextNumberOffset = offset + Dimensions::elementChoiceSize;

    return QRect(
        offset + x * nextNumberOffset,
        offset + y * nextNumberOffset,
        Dimensions::elementChoiceSize,
        Dimensions::elementChoiceSize
    );
}


/**
 * Get the bounding rectangle for a number.
 *
 * @param number
 *   A number (1-9).
 * @return
 *   A bounding rectangle.
 */
QRect SudokuCellView::getBoundingRectForChoice(int number) const {
    if (number < 1 || number > 9)
        qFatal("SudokuElement::getboundingRectForChoice(): number was not in the valid range (1-9). number: %d.", number);

    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (--number == 0)
                return getBoundingRectForChoiceByCoords(x, y);

    // This should never be reached!
    qFatal("The number %d could not be found!", number);
    return QRect();
}
