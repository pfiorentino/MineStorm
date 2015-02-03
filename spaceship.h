#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>

class SpaceShip
{
public:
    SpaceShip();
    void draw(QPainter &painter, QPoint position);
};

#endif // SPACESHIP_H
