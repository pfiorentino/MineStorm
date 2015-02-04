#ifndef SHIPBULLET_H
#define SHIPBULLET_H
#include <QPainter>
#include <QPolygon>

class shipBullet
{
public:
    shipBullet(QPoint pos);
    ~shipBullet();
    void draw(QPainter &painter);
    void bulletMove();
private:
    QPoint position;
    QPolygon bullet;
};

#endif // SHIPBULLET_H
