#include "spaceship.h"
#include <QPolygon>

SpaceShip::SpaceShip(QPoint position, int orientation):MovableObject(position) {
    _orientation = orientation;
    _acceleration = 0;
    _maxspeed = 12;
}

void SpaceShip::draw(QPainter &painter) {
    QPainterPath path;
    path.addPolygon(this->getPolygon());
    painter.drawPath(path);
}

void SpaceShip::rotateLeft(){
    _orientation += 10;
}

void SpaceShip::rotateRight(){
    _orientation -= 10;
}

void SpaceShip::accelerate() {
    ++_acceleration;

    _speed.setX(_speed.x()+(_acceleration*sin(_orientation*M_PI/180)));
    _speed.setY(_speed.y()+(_acceleration*cos(_orientation*M_PI/180)));

    if (getSpeed() > _maxspeed) {
        setDirection(_orientation);
        setSpeed(_maxspeed);
    }
}

void SpaceShip::stopAcceleration() {
    _acceleration = 0;
}

void SpaceShip::stop() {
    //Fonction utilisée pour les tests, stoppe le vaisseau
    _speed.setX(0);
    _speed.setY(0);
}

int SpaceShip::getOrientation() {
    return _orientation;
}

QPoint SpaceShip::getAbsolutePoint(QPoint relativePoint) const {
    QPoint absolutePoint = QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());

    return QPoint(sin(_orientation*M_PI/180)*(absolutePoint.x()-_position.x()) - cos(_orientation*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.x(),
                  cos(_orientation*M_PI/180)*(absolutePoint.x()-_position.x()) + sin(_orientation*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.y());
}

QPoint SpaceShip::getAbsolutePointPrec(QPoint relativePoint) const {
    QPoint absolutePoint = QPoint(_previousPosition.x()+relativePoint.x(), _previousPosition.y()+relativePoint.y());

    return QPoint(sin(_orientation*M_PI/180)*(absolutePoint.x()-_previousPosition.x()) - cos(_orientation*M_PI/180)*(absolutePoint.y()-_previousPosition.y()) + _previousPosition.x(),
                  cos(_orientation*M_PI/180)*(absolutePoint.x()-_previousPosition.x()) + sin(_orientation*M_PI/180)*(absolutePoint.y()-_previousPosition.y()) + _previousPosition.y());

}

void SpaceShip::explode(){
    std::cout<<"Le vaisseau explose !"<<std::endl;
}

QPolygon SpaceShip::getPolygon(){
    QPolygon ship;

//    ship.append(getAbsolutePoint(QPoint(-10, 0)));
//    ship.append(getAbsolutePoint(QPoint(-10, 10)));
//    ship.append(getAbsolutePoint(QPoint(0, 0)));
//    ship.append(getAbsolutePoint(QPoint(3, -3)));
//    ship.append(getAbsolutePoint(QPoint(0, -20)));
//    ship.append(getAbsolutePoint(QPoint(-3, -3)));
//    ship.append(getAbsolutePoint(QPoint(0, 0)));
//    ship.append(getAbsolutePoint(QPoint(10, 10)));
//    ship.append(getAbsolutePoint(QPoint(10, 0)));

    ship.append(getAbsolutePoint(QPoint(0, -10)));
    ship.append(getAbsolutePoint(QPoint(-10, -10)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(3, 3)));
    ship.append(getAbsolutePoint(QPoint(20, 0)));
    ship.append(getAbsolutePoint(QPoint(3, -3)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(-10, 10)));
    ship.append(getAbsolutePoint(QPoint(0, 10)));

    return ship;
}


QPolygon SpaceShip::getPolygonDetection(){
    QPolygon ship;

    ship.append(getAbsolutePoint(QPoint(0, -10)));
    ship.append(getAbsolutePoint(QPoint(-10, -10)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(3, 3)));
    ship.append(getAbsolutePoint(QPoint(20, 0)));
    ship.append(getAbsolutePoint(QPoint(3, -3)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(-10, 10)));
    ship.append(getAbsolutePoint(QPoint(0, 10)));

    ship.append(getAbsolutePointPrec(QPoint(0, -10)));
    ship.append(getAbsolutePointPrec(QPoint(-10, -10)));
    ship.append(getAbsolutePointPrec(QPoint(0, 0)));
    ship.append(getAbsolutePointPrec(QPoint(3, 3)));
    ship.append(getAbsolutePointPrec(QPoint(20, 0)));
    ship.append(getAbsolutePointPrec(QPoint(3, -3)));
    ship.append(getAbsolutePointPrec(QPoint(0, 0)));
    ship.append(getAbsolutePointPrec(QPoint(-10, 10)));
    ship.append(getAbsolutePointPrec(QPoint(0, 10)));

    return ship;

}


