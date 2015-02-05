#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>
#include<math.h>
#include "shipbullet.h"

class SpaceShip
{
public:
    SpaceShip(QPoint position);
    void draw(QPainter &painter);
    void spawn();
    void turnLeft();
    void turnRight();
    void move();
    void fire(QPainter &painter);
private:
    QPoint _position;
    double _angle;
};

#endif // SPACESHIP_H
