#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "movableobject.h"

#include "shipbullet.h"

class SpaceShip : public MovableObject
{
public:
    SpaceShip(QPoint position, int orientation = 180);
    void draw(QPainter &painter);
    void rotateLeft();
    void rotateRight();
    void accelerate();
    void stopAcceleration();
    int getOrientation();
    void stop();
    QPolygon getPolygon() const;
    bool isInvincible();
    void resetGodMode();
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    int _orientation;
    int _acceleration;
    int _maxspeed;
    int _godModeDuration;
};

#endif // SPACESHIP_H
