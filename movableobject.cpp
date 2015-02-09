#include "movableobject.h"

MovableObject::MovableObject(QPoint position, int speed, int direction)
    :_position(position), _direction(direction) {
    setSpeed(speed);
}

QPoint MovableObject::getPosition() {
    return _position;
}

void MovableObject::setSpeed(int speed) {
    _speed.setX(speed*sin(_direction*M_PI/180));
    _speed.setY(speed*cos(_direction*M_PI/180));
}

int MovableObject::getSpeed() {
    return sqrt(_speed.x()*_speed.x()+_speed.y()*_speed.y());
}

void MovableObject::setDirection(int angle) {
    _direction = angle;
}

int MovableObject::getDirection(){
    return _direction;
}

void MovableObject::move(QSize bounds) {
    _position.setX(_position.x()+_speed.x());
    _position.setY(_position.y()+_speed.y());

    if (_position.x() < 0){
        _position.setX(_position.x()+bounds.width());
    }
    else if (_position.x() > bounds.width()) {
        _position.setX(_position.x()-bounds.width());
    }

    if (_position.y() < 0){
        _position.setY(_position.y()+bounds.height());
    }
    else if (_position.y() > bounds.height()) {
        _position.setY(_position.y()-bounds.height());
    }

    this->alive--;
}
