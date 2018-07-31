#include "sudokugamescene.h"

#include "dimensions.h"
#include "sudokucellview.h"

SudokuGameScene::SudokuGameScene(QAction * mainWindowPauseAction)
{
    Q_UNUSED(mainWindowPauseAction);

    setSceneRect(0, 0, Dimensions::sceneWidth, Dimensions::sceneHeight);

    this->cellViewArray = new SudokuCellView * [9];
    this->theBoxes = new QGraphicsRectItem[9];

    for (int i = 0; i < 9; i++)
        this->cellViewArray[i] = new SudokuCellView[9];

    // Now add them to the scene.
    int xOffset = 0, yOffset = 0;
    for (int i = 0; i < 9; i++) {
        xOffset += (i == 3 || i == 6) ? Dimensions::margin : 0;
        yOffset = 0;
        for (int j = 0; j < 9; j++) {
            yOffset += (j == 3 || j == 6) ? Dimensions::margin : 0;
            SudokuCellView* cellView = (&cellViewArray[i][j]);
            cellView->setPos(xOffset + Dimensions::margin + Dimensions::elementSize * i, yOffset + Dimensions::margin + Dimensions::elementSize * j);
            cellView->setX(i);
            cellView->setY(j);
            addItem(cellView);

            if ((i + 1) % 3 == 0 && (j + 1) % 3 == 0) {
                // Accentuate the boxes with thicker lines.
                static int box_id = -1;
                box_id++;
                this->theBoxes[box_id].setRect(QRectF(xOffset + Dimensions::margin + Dimensions::elementSize * (i - 2), yOffset + Dimensions::margin + Dimensions::elementSize * (j - 2), Dimensions::elementSize * 3, Dimensions::elementSize * 3));
                this->theBoxes[box_id].setPen(QPen(QColor(36, 156, 206), 2));
                addItem(&theBoxes[box_id]);
            }
        }
    }

}

SudokuGameScene::~SudokuGameScene()
{
    // Need to delete some arrays of arrays.
    for (int i = 0; i < 9; i++)
    {
        delete [] this->cellViewArray[i];
    }
    delete [] this->cellViewArray;
    delete [] this->theBoxes;
}

void SudokuGameScene::renderBoard(QPainter *painter, const QRectF &target)
{
    render(painter, target, QRect(0, 0, Dimensions::boardSize, Dimensions::boardSize));
}

