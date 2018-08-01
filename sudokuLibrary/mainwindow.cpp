#include "mainwindow.h"

#include "sudokugameview.h"
#include "dimensions.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    SudokuGameView* gameView = new SudokuGameView(this);
    this->setCentralWidget(gameView);

    setWindowTitle("Sudoku");
    setFixedSize(Dimensions::gameSize + Dimensions::margin
                 , Dimensions::gameSize + Dimensions::margin);

}

MainWindow::~MainWindow()
{
}
