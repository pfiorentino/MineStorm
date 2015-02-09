#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QPainter>

class Explosion
{
public:
    Explosion(int size, QPoint position);
    ~Explosion();

    void draw(QPainter &painter);
    QPolygon getPolygon();
private:
    int _size;
    QPoint _position;
    QPoint getAbsolutePoint(QPoint relativePoint) const;
};

#endif // EXPLOSION_H
