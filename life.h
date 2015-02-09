#ifndef LIFE_H
#define LIFE_H

#include <QPainter>
#include<iostream>
class Life
{
public:
    Life();
    void draw(QPainter &painter, QPoint position);
    void drawAllLifes(QPainter &painter, int nbLife);
    void looseLife();

private:
    std::vector<QPoint> _listLife;
};

#endif // LIFE_H
