#include "mine.h"

#include <QPolygon>

Mine::Mine(int size): _size(size)
{

}

Mine::~Mine()
{

}

void Mine::draw(QPainter &painter, QPoint position) {
    QPolygon mine;

    mine.append(QPoint(position.x(), position.y()+(60/_size)));
    mine.append(QPoint(position.x()-(15/_size), position.y()+(7/_size)));
    mine.append(QPoint(position.x()-(45/_size), position.y()-(30/_size)));
    mine.append(QPoint(position.x(), position.y()-(7/_size)));
    mine.append(QPoint(position.x()+(45/_size), position.y()-(30/_size)));
    mine.append(QPoint(position.x()+(15/_size), position.y()+(7/_size)));

    painter.drawPolygon(mine);
}

void Mine::mineSpawn(){

}

void Mine::mineMove(){

}

void Mine::mineEclose(){

}

int Mine::getMinePositionX(){
    return this->minePositionX
}

void Mine::setMinePositionX(int position){
    this->minePositionX = position;
}

int Mine::getMinePositionY(){
    return this->minePositionY;
}

void Mine::setMinePositionY(int position){
    this->minePositionY = position;
}
