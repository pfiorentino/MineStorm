#include "spaceship.h"

#include <QPolygon>

SpaceShip::SpaceShip(QPoint position):MovableObject(position) {
    _angle = 0;
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
}

void SpaceShip::turnRight(){
    _angle = abs((_angle + 10)%360);
}

void SpaceShip::accelerate() {
    QPoint factor;

    if (_angle > 0 && _angle < 180){
        factor.setX(1);
    } else if (_angle > 180) {
        factor.setX(-1);
    }

    if (_angle > 90 && _angle < 270){
        factor.setY(1);
    } else if (_angle < 90 || _angle > 270) {
        factor.setY(-1);
    }

    MovableObject::accelerate(factor);
}

void SpaceShip::fire(QPainter &painter){
}

QPoint SpaceShip::getAbsolutePoint(QPoint relativePoint) const {
    QPoint absolutePoint = QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());
    return QPoint(cos(_angle*M_PI/180)*(absolutePoint.x()-_position.x()) - sin(_angle*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.x(),
                  sin(_angle*M_PI/180)*(absolutePoint.x()-_position.x()) + cos(_angle*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.y());
}
