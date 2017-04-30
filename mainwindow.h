#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "solverthread.h"
#include "renderthread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QVector<GridUpdateEvent *> ev;
    Square * s[3][3];
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void getEvents(QVector<GridUpdateEvent *> events);
    void doneWaiting();
protected:
    void paintEvent(QPaintEvent * e);

private:
    SolverThread solver;
    RenderThread render;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
