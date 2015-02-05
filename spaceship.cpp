#include "spaceship.h"

#include <QPolygon>
#include <math.h>

SpaceShip::SpaceShip(QPoint position): _position(position) {
    _angle = 0;
    _speed = QPoint(0,0);
    _debug = 0;
}

void SpaceShip::draw(QPainter &painter) {
    QPolygon ship;

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

void SpaceShip::turnLeft(){
    _angle = (_angle - 10)%360;
    if (_angle < 0)
        _angle = _angle+360;

    _debug = _angle;
}

void SpaceShip::turnRight(){
    _angle = abs((_angle + 10)%360);
    _debug = _angle;
}

void SpaceShip::accelerate() {
    if (_angle > 0 && _angle < 180 && _speed.x() < 10){
        _speed.setX(_speed.x()+1);
    } else if (_angle > 180 && _speed.x() > -10) {
        _speed.setX(_speed.x()-1);
    } else if (_angle == 0 || _angle == 180) {
        //_speed.setX(0);
    }

    if (_angle > 90 && _angle < 270 && _speed.y() < 10){
        _speed.setY(_speed.y()+1);
    } else if ((_angle < 90 || _angle > 270) && _speed.y() > -10) {
        _speed.setY(_speed.y()-1);
    } else if (_angle == 90 || _angle == 270) {
        //_speed.setY(0);
    }
}

void SpaceShip::move(){
    _previousPosition = QPoint(_position.x(), _position.y());

    if (_position.x() < 0){
        _position.setX(400);
        _position.setY(600-_position.y());
    } else if (_position.x() > 400) {
        _position.setX(0);
        _position.setY(600-_position.y());
    } else {
        _position.setX(_position.x()+_speed.x());
    }

    if (_position.y() < 0){
        _position.setY(600);
        _position.setX(400-_position.x());
    } else if (_position.y() > 600) {
        _position.setY(0);
        _position.setX(400-_position.x());
    } else {
        _position.setY(_position.y()+_speed.y());
    }
}

void SpaceShip::fire(QPainter &painter){
    shipBullet bul(_position);
    bul.draw(painter);
    bul.bulletMove();
}

int SpaceShip::getSpeed() {
    return _debug;
}

QPoint SpaceShip::getAbsolutePoint(QPoint relativePoint) const {
    float angleRad = degToRad(_angle);
    QPoint absolutePoint = QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());
    return QPoint(cos(_angle*M_PI/180)*(absolutePoint.x()-_position.x()) - sin(_angle*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.x(),
                  sin(_angle*M_PI/180)*(absolutePoint.x()-_position.x()) + cos(_angle*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.y());
}

float SpaceShip::degToRad(int degValue) const {
    return degValue*(M_PI/180);
}
