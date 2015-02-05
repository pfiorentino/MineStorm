#include "spaceship.h"

#include <QPolygon>
#include <math.h>

SpaceShip::SpaceShip(QPoint position): _position(position) {
    _angle = 0;
}

void SpaceShip::draw(QPainter &painter) {
    QPolygon ship;

//    ship.append(QPoint(_position.x()-10, _position.y()));
//    ship.append(QPoint(_position.x()-10, _position.y()+10));
//    ship.append(QPoint(_position.x(), _position.y()));
//    ship.append(QPoint(_position.x()+3, _position.y()-3));
//    ship.append(QPoint(_position.x(), _position.y()-20));
//    ship.append(QPoint(_position.x()-3, _position.y()-3));
//    ship.append(QPoint(_position.x(), _position.y()));
//    ship.append(QPoint(_position.x()+10, _position.y()+10));
//    ship.append(QPoint(_position.x()+10, _position.y()));

    ship.append(getAbsolutePoint(QPoint(-10, 0)));
    ship.append(getAbsolutePoint(QPoint(-10, 10)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(3, -3)));
    ship.append(getAbsolutePoint(QPoint(0, -20)));
    ship.append(getAbsolutePoint(QPoint(-3, -3)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(10, 10)));
    ship.append(getAbsolutePoint(QPoint(10, 0)));

    QPainterPath path;
    path.addPolygon(ship);

    painter.drawPath(path);
}

void SpaceShip::spawn(){

}

int SpaceShip::getAngle() {
    return _angle;
}

void SpaceShip::turnLeft(){
    _angle = _angle - 10;
}

void SpaceShip::turnRight(){
    _angle = _angle + 10;
}

void SpaceShip::move(){
    //this->ship.translated(5,0);
}

void SpaceShip::fire(QPainter &painter){
    shipBullet bul(_position);
    bul.draw(painter);
    bul.bulletMove();
}

QPoint SpaceShip::getAbsolutePoint(QPoint relativePoint) const {
    float angleRad = _angle*(M_PI/180);
    QPoint absolutePoint = QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());
    return QPoint(cos(angleRad)*(absolutePoint.x()-_position.x()) - sin(angleRad)*(absolutePoint.y()-_position.y()) + _position.x(),
                  sin(angleRad)*(absolutePoint.x()-_position.x()) + cos(angleRad)*(absolutePoint.y()-_position.y()) + _position.y());
}
