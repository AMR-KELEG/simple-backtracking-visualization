#include "gridupdateevent.h"

GridUpdateEvent::GridUpdateEvent(int r,int c,QColor color)
{
    row = r;
    col = c;
    this->color = color;
}

GridUpdateEvent::~GridUpdateEvent()
{

}

