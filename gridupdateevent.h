#ifndef GRIDUPDATEEVENT_H
#define GRIDUPDATEEVENT_H
#include <QColor>

class GridUpdateEvent
{
private:

public:
    int row;
    int col;
    QColor color;
    GridUpdateEvent(int r,int c,QColor color);
    ~GridUpdateEvent();
};

#endif // GRIDUPDATEEVENT_H
