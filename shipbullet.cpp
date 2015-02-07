#include "shipbullet.h"

ShipBullet::ShipBullet(QPoint position, int speed, int orientation):MovableObject(position, speed, orientation)
{

}

void ShipBullet::draw(QPainter &painter) {
    painter.drawPoint(_position);
}

bool ShipBullet::outOfScreen(){
    if (_position.x() > 400 || _position.x() < 0 ||
        _position.y() > 600 || _position.y() < 0)
        return true;
    else
        return false;
}
