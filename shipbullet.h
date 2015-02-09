#ifndef SHIPBULLET_H
#define SHIPBULLET_H
#include "movableobject.h"

class ShipBullet : public MovableObject
{
public:
    ShipBullet(QPoint position, int speed, int orientation);
    void draw(QPainter &painter);
    int getAlive();
    void explode();
    QPolygon getPolygon();
    QPolygon getPolygonDetection();
};

#endif // SHIPBULLET_H
