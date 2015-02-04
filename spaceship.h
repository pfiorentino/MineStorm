#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>
#include<math.h>
#include "shipbullet.h"

class SpaceShip
{
public:
    SpaceShip(int x, int y);
    ~SpaceShip();
    void draw(QPainter &painter);
    void spaceShipSpawn();
    void spaceShipTurnLeft();
    void spaceShipTurnRight();
    void spaceShipMove();
    void spaceShipFire(QPainter &painter);
private:
    QPolygon ship;
    QPoint position;
    double angle;
};

#endif // SPACESHIP_H
