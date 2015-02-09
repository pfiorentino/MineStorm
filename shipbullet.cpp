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
    QPoint pos1 (this->getPosition().x(),this->getPosition().y());
    QPoint pos2 (this->_previousPosition.x(),this->_previousPosition.y());
    QPoint pos3 (this->_previousPosition.x()+1,this->_previousPosition.y());
    bullet.append(pos1);
    bullet.append(pos2);
    bullet.append(pos3);

    return bullet;
}
