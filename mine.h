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
    int getMinePositionX() const;
    void setMinePositionX(int position);
    int getMinePositionY() const;
    void setMinePositionY(int position);
private:
    int _size;
    QPoint position;
};

#endif // MINE_H
