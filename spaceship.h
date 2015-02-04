#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>

class SpaceShip
{
public:
    SpaceShip(int x, int y);
    ~SpaceShip();
    void draw(QPainter &painter);
    void spaceShipSpawn();
    void spaceShipTurn();
    void spaceShipMove();
    void spaceShipFire();
    int getSpaceShipPositionX() const;
    void setSpaceShipPositionX(int pos);
    int getSpaceShipPositionY() const;
    void setSpaceShipPositionY(int pos);
private:
    QPoint position;
};

#endif // SPACESHIP_H
