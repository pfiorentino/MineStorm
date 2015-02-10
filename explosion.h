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
    bool toRemove() const;
private:
    int _currentSize;
    int _maxSize;
    QPoint _position;
    QPoint getAbsolutePoint(QPoint relativePoint) const;
};

#endif // EXPLOSION_H
