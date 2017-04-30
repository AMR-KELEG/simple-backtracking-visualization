#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    solver(),
    render()
{
    ui->setupUi(this);

    s[0][0]=new Square(20,20,40,40);
    s[0][1]=new Square(20,60,40,40);
    s[0][2]=new Square(20,100,40,40);
    s[1][0]=new Square(60,20,40,40);
    s[1][1]=new Square(60,60,40,40);
    s[1][2]=new Square(60,100,40,40);
    s[2][0]=new Square(100,20,40,40);
    s[2][1]=new Square(100,60,40,40);
    s[2][2]=new Square(100,100,40,40);

    connect(&solver,SIGNAL(doneSolution(QVector<GridUpdateEvent *>)),this,SLOT(getEvents(QVector<GridUpdateEvent *>)));
    connect(&render,SIGNAL(doneWaiting()),this,SLOT(doneWaiting()));
    solver.start();
}

void MainWindow::paintEvent(QPaintEvent * e)
{
    QPainter p;
    p.begin(this);
    for(int r=0;r<3;r++)
    {
        for (int c=0;c<3;c++)
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
