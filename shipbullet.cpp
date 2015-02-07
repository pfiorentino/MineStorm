#include "shipbullet.h"

ShipBullet::ShipBullet(QPoint position, int speed, int orientation):MovableObject(position, speed, orientation)
{
    this->alive=30;
}

QPolygon ShipBullet::draw(QPainter &painter) {
    QVector<QPoint> tab;
    tab.push_back(_position);
    QPolygon bull = QPolygon(tab);
    painter.drawPoint(_position);

    return bull;
}

bool ShipBullet::outOfScreen(){
    if (_position.x() > 400 || _position.x() < 0 ||
        _position.y() > 600 || _position.y() < 0)
        return true;
    else
        return false;
}

int ShipBullet::getAlive() {
    return this->alive;
}
