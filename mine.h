#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>

class Mine
{
public:
    Mine(int size, QPoint position);
    void draw(QPainter &painter);
    void mineSpawn();
    void mineMove();
    void mineEclose();
private:
    int _size;
    QPoint _position;
    QPoint _speed;
};

#endif // MINE_H
