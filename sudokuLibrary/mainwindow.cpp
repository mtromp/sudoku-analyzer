#include "mainwindow.h"

#include "sudokucellview.h"
#include "sudokugameview.h"
#include "dimensions.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QFrame>
#include <QLabel>

// 20180729: Try to use SudokuScene from the sudoku code by Wim Leers
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->gameScene = new SudokuGameScene();
    this->gameView = new SudokuGameView(this->gameScene);

    this->gameView->setEnabled(false);
    setCentralWidget(this->gameView);
    setupWindow();

    setAttribute(Qt::WA_DeleteOnClose, true);
    show();
}

MainWindow::~MainWindow()
{
    delete this->gameScene;
    delete this->gameView;
}

void MainWindow::setupWindow(void)
{
    setWindowTitle("Sudoku Analyzer");

    // Set the Window size and center it.
    int height = Dimensions::sceneHeight;
    int width = Dimensions::sceneWidth;
    QDesktopWidget * d = QApplication::desktop();
    int x = (d->width() - width) / 2;
    int y = (d->height() - height) / 2;
    setGeometry(x, y, width, height);
    setMinimumSize(width, height);

}
