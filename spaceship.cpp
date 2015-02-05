#include "spaceship.h"

#include <QPolygon>

SpaceShip::SpaceShip(QPoint position): _position(position) {
    _angle = 0;
}

void SpaceShip::draw(QPainter &painter) {
    QPolygon ship;

    ship.append(QPoint(_position.x()-10, _position.y()));
    ship.append(QPoint(_position.x()-10, _position.y()+10));
    ship.append(QPoint(_position.x(), _position.y()));
    ship.append(QPoint(_position.x()+3, _position.y()-3));
    ship.append(QPoint(_position.x(), _position.y()-20));
    ship.append(QPoint(_position.x()-3, _position.y()-3));
    ship.append(QPoint(_position.x(), _position.y()));
    ship.append(QPoint(_position.x()+10, _position.y()+10));
    ship.append(QPoint(_position.x()+10, _position.y()));

    QPainterPath path;
    path.addPolygon(ship);

    painter.drawPath(path);
}

void SpaceShip::spawn(){

}

void SpaceShip::turnLeft(){
    /*
    this->angle--;
    this->position.setX( cos(this->angle)*(x-xc) - sin(thêta)*(y-yc) + xc;
    y = sin(thêta)*(x-xc) + cos(thêta)*(y-yc) + yc;*/
}

void SpaceShip::turnRight(){

}

void SpaceShip::move(){
    //this->ship.translated(5,0);
}

void SpaceShip::fire(QPainter &painter){
    shipBullet bul(_position);
    bul.draw(painter);
    bul.bulletMove();
}
