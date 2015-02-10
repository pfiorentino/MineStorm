#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>
#include "movableobject.h"

class Mine : public MovableObject
{
public:
    Mine(int size, QPoint position, int speed, int direction);

    void draw(QPainter &painter);
    void spawn();
    void explode();
    QPolygon getPolygon();
    bool isBorn();
    void setBorn(bool born);
    void eclose();


private:
    int _size;
    bool _born;
};

#endif // MINE_H
