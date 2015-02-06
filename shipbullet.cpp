#include "shipbullet.h"

ShipBullet::ShipBullet(QPoint position, int speed, int orientation):MovableObject(position, speed, orientation)
{

}

void ShipBullet::draw(QPainter &painter) {
    painter.drawPoint(_position);
}
