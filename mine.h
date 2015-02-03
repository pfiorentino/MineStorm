#ifndef MINE_H
#define MINE_H

#include <QPainter>

class Mine
{
public:
    Mine(int size);
    void draw(QPainter &painter, QPoint position);
private:
    int _size;
};

#endif // MINE_H
