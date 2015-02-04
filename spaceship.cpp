#include "spaceship.h"

#include <QPolygon>

SpaceShip::SpaceShip(int x, int y)
{
    this->position = QPoint(x,y);
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::draw(QPainter &painter) {
    QPolygon ship;
    QPoint position = this->position;
    ship.append(QPoint(position.x()-10, position.y()));
    ship.append(QPoint(position.x()-10, position.y()+10));
    ship.append(QPoint(position.x(), position.y()));
    ship.append(QPoint(position.x()+3, position.y()-3));
    ship.append(QPoint(position.x(), position.y()-20));
    ship.append(QPoint(position.x()-3, position.y()-3));
    ship.append(QPoint(position.x(), position.y()));
    ship.append(QPoint(position.x()+10, position.y()+10));
    ship.append(QPoint(position.x()+10, position.y()));

    QPainterPath path;
    path.addPolygon(ship);

    painter.drawPath(path);
}

void SpaceShip::spaceShipSpawn(){

}

void SpaceShip::spaceShipTurn(){

}

void SpaceShip::spaceShipMove(){

}

void SpaceShip::spaceShipFire(){

}
