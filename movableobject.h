#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QPoint>
#include <QPainter>
#include <math.h>

class MovableObject
{
public:
    MovableObject(QPoint position = QPoint(0, 0), int speed = 0, int direction = 0);
    virtual void draw(QPainter &painter) = 0;

    QPoint getPosition();

    void accelerate();

    void setSpeed(int speed);
    int getSpeed();

    void setDirection(int angle);
    int getDirection();

    void move();
protected:
    QPoint _position;
    int _direction;

private:
    int _speed;
};

#endif // MOVABLEOBJECT_H
