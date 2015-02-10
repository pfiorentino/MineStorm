#include "shipbullet.h"

ShipBullet::ShipBullet(QPoint position, int speed, int orientation):
    MovableObject(position, speed, orientation), _lifeTime(30) {
}

void ShipBullet::draw(QPainter &painter) {
    painter.drawPoint(_position);
    --_lifeTime;
    //painter.drawPolygon(this->getPolygonDetection());
}

bool ShipBullet::isAlive() {
    return _lifeTime > 0;
}

QPolygon ShipBullet::getPolygon() const{
    QPolygon bullet;
    int carretSize = 3;

    bullet.append(QPoint(_position.x()+carretSize, _position.y()+carretSize));
    bullet.append(QPoint(_position.x()+carretSize, _position.y()-carretSize));
    bullet.append(QPoint(_position.x()-carretSize, _position.y()-carretSize));
    bullet.append(QPoint(_position.x()-carretSize, _position.y()+carretSize));

    return bullet;
}
