#include "renderthread.h"

RenderThread::RenderThread(QObject *parent) :
    QThread(parent)
{

}

void RenderThread::run( void)
{
    while(true)
    {
        this->msleep(300);
        emit doneWaiting();
    }
}

RenderThread::~RenderThread()
{

}

