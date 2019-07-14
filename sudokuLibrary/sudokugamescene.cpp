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
        addCellToBoxes(theCell, cellNumber);

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
    for(int i=0; i < 9; ++i)
    {
        sudokuRows[i] = new SudokuCellContainer();
    }
}

void SudokuGameScene::addCellToBoxes(SudokuCell *theCell, int cellNumber)
{
    int rowNumber = mapper.GetRow(cellNumber);
    SudokuCellContainer* rowContainer = sudokuRows[rowNumber-1];
    rowContainer->AddCell(theCell);
    // Connect cell signal to container slot
    QObject::connect(theCell, SIGNAL(CellValueSet(int)), rowContainer, SLOT(CellValueSet(int)));
}
