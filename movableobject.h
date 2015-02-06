#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QPoint>
#include <QPainter>

class MovableObject
{
public:
    MovableObject(QPoint position = QPoint(0, 0), QPoint speed = QPoint(0, 0));
    virtual void draw(QPainter &painter) = 0;
    void accelerate(QPoint factor);
    void setSpeed(QPoint speed);
    void move();

protected:
    QPoint _position;

private:
    QPoint _speed;
};

#endif // MOVABLEOBJECT_H
