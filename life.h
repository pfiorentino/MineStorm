#ifndef LIFE_H
#define LIFE_H

#include <QPainter>

class Life
{
public:
    Life();
    void draw(QPainter &painter, QPoint position);
};

#endif // LIFE_H
