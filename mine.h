#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>
#include "movableobject.h"

class Mine : public MovableObject {
public:
    Mine(int size, QPoint position, int speed, int direction);

    void draw(QPainter &painter);
    QPolygon getPolygon() const;
    bool isBorn();
    int getSize();


private:
    int _size;
    int _eclosionTime;
};

#endif // MINE_H
