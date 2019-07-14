#include "sudokugamescene.h"

#include "dimensions.h"
#include "sudokucellview.h"

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>

SudokuGameScene::SudokuGameScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, Dimensions::gameSize, Dimensions::gameSize);

    createNineBigBoxes();

    createCellContainers();

    createEightyOneCells();

}

SudokuGameScene::~SudokuGameScene()
{

}

void SudokuGameScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    QPointF position = event->scenePos();
    QGraphicsItem* selectedItem = itemAt(position, QTransform());
    SudokuCellView* mySelection = dynamic_cast<SudokuCellView*>(selectedItem);
    if (mySelection != nullptr)
    {
        mySelection->handleMouseEvent();
    }
}

void SudokuGameScene::createNineBigBoxes ()
{
    // Place a strong outline around the 9 boxes.
    int xoffset = Dimensions::margin;
    int yoffset = Dimensions::margin;


    for (int containerNumber = 1; containerNumber <=9; containerNumber++)
    {
        QGraphicsRectItem * rectItem = new QGraphicsRectItem();
        rectItem->setRect(QRectF(xoffset,
                                 yoffset,
                                 Dimensions::cellSize * 3,
                                 Dimensions::cellSize * 3
                                 ));
        rectItem->setPen(QPen(QColor(36, 156, 206), 2));
        this->addItem(rectItem);

        if ((containerNumber % 3 == 0 ))
        {
            xoffset = Dimensions::margin;
            yoffset = yoffset + Dimensions::cellSize*3 + Dimensions::margin;
        } else
        {
            xoffset = xoffset + Dimensions::cellSize*3 + Dimensions::margin;
        }

    }
}

void SudokuGameScene::createEightyOneCells()
{
    int xposition = Dimensions::margin;
    int yposition = Dimensions::margin;

    for (int cellNumber = 1; cellNumber <= 81; cellNumber++)
    {
        SudokuCell* theCell = new SudokuCell();
        SudokuCellView* cellView = new SudokuCellView(theCell);
        cellView->setPos(xposition, yposition);

        this->addItem(cellView);

        if (( cellNumber % 3 == 0 ) && ( cellNumber % 9 != 0))
        {
            xposition = xposition + Dimensions::cellSize + Dimensions::margin;
        } else if (( cellNumber % 9 == 0) && ( (cellNumber / 9) % 3 == 0 ))
        {
            xposition = Dimensions::margin;
            yposition = yposition + Dimensions::cellSize + Dimensions::margin;
        } else if (( cellNumber % 9 == 0) && ( (cellNumber / 9) % 3 != 0 ))
        {
            xposition = Dimensions::margin;
            yposition = yposition + Dimensions::cellSize;
        } else
        {
            xposition = xposition + Dimensions::cellSize;
        }
    }
}

void SudokuGameScene::createCellContainers()
{

}

void SudokuGameScene::addCellToBoxes(int theCell, int cellNumber)
{
    Q_UNUSED(theCell);
    int rowNumber = 0;
    int columnNumber = 0;
    int boxNumber = 0;

    rowNumber = cellNumber / 10;  //row = 0 for cells 1,2,3,4,5,6,7,8,9
    columnNumber = (cellNumber % 9) - 1; // column = 0 for cells 1,10,19,28,37,46....

    //rowNumber 0 goes into boxes 1, 2, 3
    //column 0 goes into boxes 1, 4, 7
    boxNumber =  rowNumber; // box = 0 for cells 1,2,3,10,11,12,28,29,30
}
