#ifndef SHIPBULLET_H
#define SHIPBULLET_H
#include "movableobject.h"

/**
 * @brief La classe ShipBullet gère les tirs du vaisseau
 */
class ShipBullet : public MovableObject
{
public:
    /**
     * @brief Constructeur
     * @param position
     * @param speed
     * @param orientation
     */
    ShipBullet(QPoint position, int speed, int orientation);
    void draw(QPainter &painter);
    bool isAlive();
    QPolygon getPolygon() const;
private:
    int _lifeTime;
};

#endif // SHIPBULLET_H
