#include "spaceship.h"

#include <QPolygon>

SpaceShip::SpaceShip(int x, int y)
{
    this->position = QPoint(x,y);
    this->ship = QPolygon();
    this->angle = 0;
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::draw(QPainter &painter) {
    QPoint position = this->position;
    this->ship.append(QPoint(position.x()-10, position.y()));
    this->ship.append(QPoint(position.x()-10, position.y()+10));
    this->ship.append(QPoint(position.x(), position.y()));
    this->ship.append(QPoint(position.x()+3, position.y()-3));
    this->ship.append(QPoint(position.x(), position.y()-20));
    this->ship.append(QPoint(position.x()-3, position.y()-3));
    this->ship.append(QPoint(position.x(), position.y()));
    this->ship.append(QPoint(position.x()+10, position.y()+10));
    this->ship.append(QPoint(position.x()+10, position.y()));

    QPainterPath path;
    path.addPolygon(this->ship);

    painter.drawPath(path);
}

void SpaceShip::spaceShipSpawn(){

}

void SpaceShip::spaceShipTurnLeft(){
    /*
    this->angle--;
    this->position.setX( cos(this->angle)*(x-xc) - sin(thêta)*(y-yc) + xc;
    y = sin(thêta)*(x-xc) + cos(thêta)*(y-yc) + yc;*/
}

void SpaceShip::spaceShipTurnRight(){

}

void SpaceShip::spaceShipMove(){
 this->ship.translated(5,0);
}

void SpaceShip::spaceShipFire(QPainter &painter){
    shipBullet bul(this->position);
    bul.draw(painter);
    bul.bulletMove();
}
