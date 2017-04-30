#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include <QThread>
#include <QVector>
#include "square.h"
#include "gridupdateevent.h"

class SolverThread : public QThread
{
    Q_OBJECT

private:
    QVector<QColor> colors;
    QVector<GridUpdateEvent *> events;
    QVector<QVector<short> > grid;
    void solve(int row,int col);
    bool validGrid(int row,int col);
    int ROWS;
    int COLS;
public:
    explicit SolverThread(int R, int C,QObject *parent = 0);
    void run( void );
    ~SolverThread();
signals:
    void doneSolution( QVector<GridUpdateEvent *> ev );
};

#endif // GRIDMANAGER_H
