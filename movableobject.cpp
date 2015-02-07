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

void MovableObject::move() {
    _position.setX(_position.x()+_speed.x());
    _position.setY(_position.y()+_speed.y());

    if (_position.x() < 0){
        _position.setX(400);
    }
    else if (_position.x() > 400) {
        _position.setX(0);
    }

    if (_position.y() < 0){
        _position.setY(600);
    }
    else if (_position.y() > 600) {
        _position.setY(0);
    }

    this->alive--;
}

/*void MovableObject::move() {
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
}*/
