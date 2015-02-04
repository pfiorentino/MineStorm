#include "mine.h"

#include <QPolygon>

Mine::Mine(int size,int x,int y): _size(size)
{
    this->position = QPoint(x,y);
}

Mine::~Mine()
{

}

void Mine::draw(QPainter &painter) {
    QPolygon mine;
    QPoint position = this->position;
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
