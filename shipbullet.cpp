#include "shipbullet.h"

ShipBullet::ShipBullet(QPoint position, int speed, int orientation):MovableObject(position, speed, orientation)
{
    this->alive=30;
}

void ShipBullet::draw(QPainter &painter) {
    painter.drawPolygon(this->getPolygon());
    //painter.drawPolygon(this->getPolygonDetection());
}

bool ShipBullet::isAlive() {
    return this->alive > 0;
}

void ShipBullet::explode(){
    //std::cout<<"La balle du vaisseau explose !"<<std::endl;
}

QPolygon ShipBullet::getPolygon(){
    QPolygon bullet;
    bullet.append(this->getPosition());
    bullet.append(QPoint(this->getPosition().x(),this->getPosition().y()+1));
    return bullet;
}

QPolygon ShipBullet::getPolygonDetection(){
    QPolygon bullet;

    bullet.append(QPoint(_position.x()+1, _position.y()+1));
    bullet.append(QPoint(_position.x()+1, _position.y()-1));
    bullet.append(QPoint(_position.x()-1, _position.y()-1));
    bullet.append(QPoint(_position.x()-1, _position.y()+1));

    return bullet;
}
