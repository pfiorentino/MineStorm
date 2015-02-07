#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>
#include "movableobject.h"

class Mine : public MovableObject
{
public:
    Mine(int size, QPoint position);
    Mine(int size, QPoint position, int speed, int orientation);

    QPolygon draw(QPainter &painter);
    void spawn();
    void move();
    void eclose();
private:
    int _size;
    QPoint _position;
    QPoint _speed;
};

#endif // MINE_H
