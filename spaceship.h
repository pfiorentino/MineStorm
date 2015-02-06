#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "movableobject.h"

#include <math.h>

#include "shipbullet.h"

class SpaceShip : public MovableObject
{
public:
    SpaceShip(QPoint position = QPoint(200, 300));
    void draw(QPainter &painter);
    void spawn();
    void turnLeft();
    void turnRight();
    void accelerate();
    void fire(QPainter &painter);
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    int _angle;
};

#endif // SPACESHIP_H
