#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QPoint>
#include <QPainter>
#include <math.h>
#include<iostream>

class MovableObject
{
public:
    MovableObject(QPoint position = QPoint(120, 120), int speed = 0, int direction = 0);
    virtual void draw(QPainter &painter) = 0;

    QPoint getPosition();

    void setSpeed(int speed);
    int getSpeed();

    void setDirection(int angle);
    int getDirection();

    void move(QSize bounds);

    virtual bool inContact(MovableObject const &object) const;

    virtual QPolygon getPolygon() const = 0;

protected:
    QPoint _position;
    int _direction;
    QPoint _speed;

private:
};

#endif // MOVABLEOBJECT_H
