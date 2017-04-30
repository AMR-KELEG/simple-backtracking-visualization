#include "square.h"


QColor Square::getColor() const
{
    return color;
}

Square::Square(int x, int y, int l, int w): QRectF(x,y,l,w)
{
    color = QColor(255,255,255);
}

void Square::setColor(QColor c)
{
    color=c;
}

Square::~Square()
{

}

