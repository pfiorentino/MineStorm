#ifndef SHIPBULLET_H
#define SHIPBULLET_H
#include "movableobject.h"

class ShipBullet : public MovableObject
{
public:
    ShipBullet(QPoint position, int speed, int orientation);
    void draw(QPainter &painter);
    bool isAlive();
    QPolygon getPolygon() const;
private:
    int _lifeTime;
};

#endif // SHIPBULLET_H
