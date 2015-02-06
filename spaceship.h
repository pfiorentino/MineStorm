#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "movableobject.h"

#include "shipbullet.h"

class SpaceShip : public MovableObject
{
public:
    SpaceShip(QPoint position = QPoint(200, 300), int orientation = 0);
    void draw(QPainter &painter);
    void rotateLeft();
    void rotateRight();
    void accelerate();
    int getOrientation();
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    int _orientation;
};

#endif // SPACESHIP_H
