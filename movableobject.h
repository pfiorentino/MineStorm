#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QPoint>
#include <QPainter>
#include <math.h>
#include<iostream>

class MovableObject
{
public:
    MovableObject(QPoint position = QPoint(0, 0), int speed = 0, int direction = 0);
    virtual void draw(QPainter &painter) = 0;

    QPoint getPosition();

    void setSpeed(int speed);
    int getSpeed();

    void setDirection(int angle);
    int getDirection();

    void move();
    void explode();

    QPolygon getPolygon();
    QPolygon getPolygonDetection();

protected:
    QPoint _position;
    int _direction;
    QPoint _speed;
    int alive;
    QPoint _previousPosition;

private:
};

#endif // MOVABLEOBJECT_H
