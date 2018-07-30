#include "sudokugameview.h"

SudokuGameView::SudokuGameView(SudokuGameScene *gameScene, QWidget *parent)
    : QGraphicsView(gameScene, parent),
      gameScene(gameScene)
{
    // Performance
    setRenderHints(
       QPainter::Antialiasing
      | QPainter::TextAntialiasing
      | QPainter::SmoothPixmapTransform
      | QPainter::HighQualityAntialiasing
    );

//    setOptimizationFlag(
//       QGraphicsView::DontClipPainter
//       | QGraphicsView::DontAdjustForAntialiasing
//       | QGraphicsView::DontSavePainterState
//    );
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

    // Appearance
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameStyle(QFrame::NoFrame);

    // Background
    setBackgroundBrush(QColor(170, 218, 238));
}
