#include "sudokucellview.h"
#include "dimensions.h"


SudokuCellView::SudokuCellView(void) : QObject(nullptr)
{
//    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

//SudokuCellView::~SudokuCellView()
//{

//}

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
