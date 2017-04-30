#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDebug>
MainWindow::MainWindow(int R,int C,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    solver(R,C),
    render()
{
    ui->setupUi(this);

    s= QVector<QVector<Square *> >(R,QVector<Square *>(C));
    ROWS=R;
    COLS=C;
    int y=20;
    for(int row=0;row<R;row++)
    {
        int x=20;
        for(int col=0;col<C;col++)
        {
            s[row][col]=new Square(x,y,40,40);
            x+=40;
        }
        y+=40;
    }

    connect(&solver,SIGNAL(doneSolution(QVector<GridUpdateEvent *>)),this,SLOT(getEvents(QVector<GridUpdateEvent *>)));
    connect(&render,SIGNAL(doneWaiting()),this,SLOT(doneWaiting()));
    solver.start();
}

void MainWindow::paintEvent(QPaintEvent * e)
{
    QPainter p;
    p.begin(this);
    for(int r=0;r<ROWS;r++)
    {
        for (int c=0;c<COLS;c++)
        {
            p.setBrush(s[r][c]->getColor());
            p.drawRect(*(s[r][c]));
        }
    }
    p.end();
}

void MainWindow::getEvents(QVector<GridUpdateEvent *> events)
{
    ev = events;
    render.start();
}

void MainWindow::doneWaiting()
{
// Consume event
    if(!ev.empty())
    {
        GridUpdateEvent * e = ev[0];
        s[e->row][e->col]->setColor(e->color);
        ev.pop_front();
    }
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
