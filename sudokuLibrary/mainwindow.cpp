#include "mainwindow.h"

#include <QFrame>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Create the widget and the layout. Passing widget into
    // layout will set the widget's layout.
    QWidget *gridWidget = new QWidget();
    this->sudokuGrid = new QGridLayout(gridWidget);
    this->sudokuGrid->setSpacing(0);
    this->sudokuGrid->setHorizontalSpacing(0);
    this->sudokuGrid->setVerticalSpacing(0);

    for (int i=0; i<9; i++)
    {
        QFrame *frame = new QFrame();
        frame->setFrameStyle(QFrame::Box);
        frame->setFixedSize(300,300);
        frame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sudokuGrid->addWidget(frame, (i) / 3, (i) % 3);
        QGridLayout *frameLayout = new QGridLayout(frame);
        for (int j=0; j<9; j++)
        {
            QFrame *innerFrame = new QFrame();
            innerFrame->setFrameStyle(QFrame::Box);
            innerFrame->setFixedSize(100,100);
            innerFrame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            frameLayout->addWidget(innerFrame, (j) / 3, (j) % 3);
        }

    }

    this->setCentralWidget(gridWidget);

    setWindowTitle("Sudoku");
    setFixedSize(950, 950);

}

MainWindow::~MainWindow()
{
    delete sudokuGrid;
}
