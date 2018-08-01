#include "sudokugamescene.h"

#include "dimensions.h"

SudokuGameScene::SudokuGameScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, Dimensions::gameSize, Dimensions::gameSize);
    this->addText("This is a Test");
}

SudokuGameScene::~SudokuGameScene()
{

}
