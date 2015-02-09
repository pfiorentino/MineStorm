#include "shipbullet.h"

ShipBullet::ShipBullet(QPoint position, int speed, int orientation):MovableObject(position, speed, orientation)
{
    this->alive=30;
}

void ShipBullet::draw(QPainter &painter) {
    painter.drawPolygon(this->getPolygon());
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

void ShipBullet::explode(){
    std::cout<<"La balle du vaisseau explose !"<<std::endl;
}

QPolygon ShipBullet::getPolygon(){
    QPolygon bullet;
    bullet.append(this->getPosition());
    return bullet;
}
