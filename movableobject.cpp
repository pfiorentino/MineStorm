#include "movableobject.h"

MovableObject::MovableObject(QPoint position, int speed, int direction)
    :_position(position), _direction(direction), _speed(speed) {

}

QPoint MovableObject::getPosition() {
    return _position;
}

void MovableObject::accelerate() {
    if (_speed < 10)
        _speed++;
}

void MovableObject::setSpeed(int speed) {
    _speed = speed;
}

int MovableObject::getSpeed() {
    return _speed;
}

void MovableObject::setDirection(int angle) {
    _direction = angle;
}

int MovableObject::getDirection(){
    return _direction;
}

void MovableObject::move() {
    QPoint vectorSpeed;
    vectorSpeed.setX(_speed*cos(_direction*M_PI/180));
    vectorSpeed.setY(-(_speed*sin(_direction*M_PI/180)));

    if (_position.x() < 0){
        _position.setX(400);
        _position.setY(std::max(600-_position.y(), 0));
    } else if (_position.x() > 400) {
        _position.setX(0);
        _position.setY(std::max(600-_position.y(), 0));
    } else {
        _position.setX(_position.x()+vectorSpeed.x());
    }

    if (_position.y() < 0){
        _position.setY(600);
        _position.setX(std::max(400-_position.x(), 0));
    } else if (_position.y() > 600) {
        _position.setY(0);
        _position.setX(std::max(400-_position.x(), 0));
    } else {
        _position.setY(_position.y()+vectorSpeed.y());
    }
}
