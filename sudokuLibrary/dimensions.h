#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <QString>
// Copied from Sudoku by Wim Leers
class Dimensions {
public:
    static const int margin = 10;

    static const int elementChoiceSize = 12;
    static const int elementSize       = 50;

    static const int boardSize = elementSize * 9 + 4 * margin;

    static const int pauseOverlaySize = 5 * elementSize + 2 * margin;

    static const int HUDWidth = 150;
    static const int HUDHeight = boardSize - 2 * margin;

    static const int sceneWidth    = boardSize + 2 * margin + HUDWidth + margin;
    static const int sceneHeight   = boardSize;
    inline static double sceneRatio(void) { return (double) sceneWidth / sceneHeight; }

    static double scaleWithTextLength(QString text, QString translatedText) { return (double) text.size() / translatedText.size(); }
};

#endif // DIMENSIONS_H
