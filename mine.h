#ifndef MINE_H
#define MINE_H

#include <QPainter>

class Mine
{
public:
    Mine(int size);
    ~Mine();
    void draw(QPainter &painter, QPoint position);
    void mineSpawn();
    void mineMove();
    void mineEclose();
    int getMinePositionX() const;
    void setMinePositionX(int position);
    int getMinePositionY() const;
    void setMinePositionY(int position);
private:
    int _size;
};

#endif // MINE_H
