#include "solverthread.h"
#include <QDebug>
SolverThread::SolverThread(QObject *parent) :
    QThread(parent)
{
    colors.push_back(QColor(255,255,255)); // White
    colors.push_back(QColor(255,0,0)); // Red
    colors.push_back(QColor(0,0,255)); // Blue
    colors.push_back(QColor(0,255,0)); // Green
    colors.push_back(QColor(255,255,0)); // Yellow
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
            grid[r][c]=0;
    }
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
            if(row+dx<0 || row+dx>2 || col+dy<0 || col+dy>2)
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
    if(row == 3)
        return ;
    if(col == 3)
    {
        solve(row+1,0);
        return ;
    }
    if(col == -1)
    {
        solve(row-1,2);
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
