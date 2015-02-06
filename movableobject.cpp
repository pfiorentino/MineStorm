#include "movableobject.h"

MovableObject::MovableObject(QPoint position, QPoint speed)
    :_position(position), _speed(speed) {

}

void MovableObject::accelerate(QPoint factor) {
    _speed.setX(_speed.x()+factor.x());
    _speed.setY(_speed.y()+factor.y());

    if (_speed.x() > 10)
        _speed.setX(10);
    if (_speed.x() < -10)
        _speed.setX(-10);

    if (_speed.y() > 10)
        _speed.setY(10);
    if (_speed.y() < -10)
        _speed.setY(-10);
}

void MovableObject::setSpeed(QPoint speed) {
    _speed = speed;
}

void MovableObject::move() {
    if (_position.x() < 0){
        _position.setX(400);
        _position.setY(std::max(600-_position.y(), 0));
    } else if (_position.x() > 400) {
        _position.setX(0);
        _position.setY(std::max(600-_position.y(), 0));
    } else {
        _position.setX(_position.x()+_speed.x());
    }

    if (_position.y() < 0){
        _position.setY(600);
        _position.setX(std::max(400-_position.x(), 0));
    } else if (_position.y() > 600) {
        _position.setY(0);
        _position.setX(std::max(400-_position.x(), 0));
    } else {
        _position.setY(_position.y()+_speed.y());
    }
}
