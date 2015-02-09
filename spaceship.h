#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "movableobject.h"

#include "shipbullet.h"

class SpaceShip : public MovableObject
{
public:
    SpaceShip(QPoint position = QPoint(200, 300), int orientation = 180);
    void draw(QPainter &painter);
    void rotateLeft();
    void rotateRight();
    void accelerate();
    void stopAcceleration();
    int getOrientation();
    void stop();
    void explode();
    QPolygon getPolygon();
    QPolygon getPolygonDetection();

private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    QPoint getAbsolutePointPrec(QPoint relativePoint) const;
    int _orientation;
    int _acceleration;
    int _maxspeed;
};

#endif // SPACESHIP_H
