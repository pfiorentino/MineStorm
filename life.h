#ifndef LIFE_H
#define LIFE_H

#include <QPainter>
#include<iostream>
class Life
{
public:
    Life(QPoint position);
    void draw(QPainter &painter);

private:
    QPoint _position;
};

#endif // LIFE_H
