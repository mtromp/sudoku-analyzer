#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>

class SudokuGameScene;
class SudokuGameView;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

signals:

public slots:

private:
    void setupWindow(void);
    SudokuGameView* gameView;
    SudokuGameScene* gameScene;
};

#endif // MAINWINDOW_H
