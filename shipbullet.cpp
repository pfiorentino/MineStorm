#include "shipbullet.h"

shipBullet::shipBullet(QPoint pos)
{
    this->bullet = QPolygon();
    this->position = pos;
}

shipBullet::~shipBullet(){

}

void shipBullet::bulletMove(){
    this->bullet.translate(20,0);
}

void shipBullet::draw(QPainter &painter){

}
