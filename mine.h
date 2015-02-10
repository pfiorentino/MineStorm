#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>
#include "movableobject.h"

class Mine : public MovableObject {
public:
    Mine(int size, QPoint position, int speed, int direction);

    void draw(QPainter &painter);
    void spawn();
    QPolygon getPolygon();
    bool isBorn();
    void setBorn(bool born);
    void eclose();
    int getSize();


private:
    int _size;
    bool _born;
    int _eclosionTime;
};

#endif // MINE_H
