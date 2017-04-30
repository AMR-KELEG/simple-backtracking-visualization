#include "solverthread.h"
#include <QDebug>
SolverThread::SolverThread(int R,int C,QObject *parent) :
    QThread(parent)
{
    colors.push_back(QColor(255,255,255)); // White
    colors.push_back(QColor(75,0,130));
    colors.push_back(QColor(139,0,139));
    colors.push_back(QColor(153,50,204));
    colors.push_back(QColor(186,85,211));
    grid = QVector<QVector<short> >(R,QVector<short>(C,0));
    ROWS = R;
    COLS = C;
}

SolverThread::~SolverThread()
{

}

void SolverThread::run( void )
{
    solve(0,0);
    emit doneSolution(events);
}

bool SolverThread::validGrid(int row,int col){
    for(int dx=-1; dx < 2 ;dx++)
    {
        for(int dy=-1; dy < 2;dy++)
        {
            if(dx==0 && dy==0)
                continue;
            if(row+dx<0 || row+dx>ROWS-1 || col+dy<0 || col+dy>COLS-1)
                continue;
            if(grid[row][col]==grid[row+dx][col+dy])
                return false;
        }
    }
    return true;
}

void SolverThread::solve(int row,int col)
{
    //Done Backtracking
//    qDebug()<<row<<" "<<col<<"\n";
    if(row == ROWS)
        return ;
    if(col == COLS)
    {
        solve(row+1,0);
        return ;
    }
    if(col == -1)
    {
        solve(row-1,COLS-1);
        return ;
    }
    if(grid[row][col] == 4)
    {
        // Make it white
        grid[row][col]=0;
        events.push_back(new GridUpdateEvent(row,col,colors[0]));
        solve(row,col-1);
        return ;
    }
    grid[row][col]++;
    events.push_back(new GridUpdateEvent(row,col,colors[grid[row][col]]));
    if(validGrid(row,col))
    {
        solve(row,col+1);
    }
    else
    {
        solve(row,col);
    }

}
