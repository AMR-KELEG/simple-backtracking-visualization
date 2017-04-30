#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H
#include <QThread>

class RenderThread : public QThread
{
    Q_OBJECT
public:
    explicit RenderThread(QObject *parent = 0);
    ~RenderThread();
    void run( void );
signals:
    void doneWaiting();
};

#endif // RENDERTHREAD_H
