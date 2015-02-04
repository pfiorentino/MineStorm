#ifndef MINE_H
#define MINE_H

#include <QPainter>

class Mine
{
public:
    Mine(int size,int x, int y);
    ~Mine();
    void draw(QPainter &painter);
    void mineSpawn();
    void mineMove();
    void mineEclose();
private:
    int _size;
    QPoint position;
    int moveX;
    int moveY;
};

#endif // MINE_H
