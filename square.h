#ifndef SQUARE_H
#define SQUARE_H
#include <QRectF>
#include <QColor>
class Square : public QRectF
{
private:
    QColor color;
public:
    Square(int x, int y, int l, int w);
    ~Square();
    QColor getColor() const;
    void setColor(QColor c);
};

#endif // SQUARE_H
