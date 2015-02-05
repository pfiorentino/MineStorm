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
    void turnLeft();
    void turnRight();
    void accelerate();
    void move();
    void fire(QPainter &painter);
    int getSpeed();
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    float degToRad(int degValue) const;
    QPoint _position;
    QPoint _previousPosition;
    QPoint _speed;
    int _angle;
    int _debug;
};

#endif // SPACESHIP_H
