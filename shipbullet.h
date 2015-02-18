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
     * @param position : position de base, celle du vaisseau au moment du tir
     * @param speed : vitesse de la balle
     * @param orientation : orientation de la balle, celle du vaisseau au moment du tir
     */
    ShipBullet(QPoint position, int speed, int orientation);
    /**
     * @brief Méthode d'affichage
     * @param painter
     */
    void draw(QPainter &painter);
    /**
     * @brief Test de longévité du tir
     * @return return true si la durée de vie >0, false sinon
     */
    bool isAlive();

    QPolygon getPolygon() const;
private:
    int _lifeTime;
};

#endif // SHIPBULLET_H
