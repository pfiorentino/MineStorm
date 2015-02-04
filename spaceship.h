#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>

class SpaceShip
{
public:
    SpaceShip();
    ~SpaceShip();
    void draw(QPainter &painter, QPoint position);
    void spaceShipSpawn();
    void spaceShipTurn();
    void spaceShipMove();
    void spaceShipFire();
    int getSpaceShipPositionX() const;
    void setSpaceShipPositionX(int pos);
    int getSpaceShipPositionY() const;
    void setSpaceShipPositionY(int pos);
};

#endif // SPACESHIP_H
