#include "renderthread.h"

RenderThread::RenderThread(QObject *parent) :
    QThread(parent)
{

}

void RenderThread::run( void)
{
    while(true)
    {
        this->msleep(1000);
        emit doneWaiting();
    }
}

RenderThread::~RenderThread()
{

}

