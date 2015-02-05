#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>
#include <math.h>
#include "shipbullet.h"

class SpaceShip
{
public:
    SpaceShip(QPoint position = QPoint(200, 300));
    void draw(QPainter &painter);
    void spawn();
    int getAngle();
    void turnLeft();
    void turnRight();
    void move();
    void fire(QPainter &painter);
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    QPoint _position;
    int _angle;
    int _speed;
};

#endif // SPACESHIP_H
