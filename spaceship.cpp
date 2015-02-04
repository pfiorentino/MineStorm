#include "spaceship.h"

#include <QPolygon>

SpaceShip::SpaceShip()
{

}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::draw(QPainter &painter, QPoint position) {
    QPolygon ship;

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

int SpaceShip::getSpaceShipPositionX(){
    return this->spaceShipPositionX;
}

void SpaceShip::setSpaceShipPositionX(int pos){
    this->spaceShipPositionX = pos;
}

int SpaceShip::getSpaceShipPositionY(){
    return this->spaceShipPositionY;
}

void SpaceShip::setSpaceShipPositionY(int pos){
    this->spaceShipPositionY = pos;
}
