#include "mine.h"

#include <QPolygon>

Mine::Mine(int size, QPoint position): _size(size), _position(position) {
    _speed.setX(rand()%200 - 100);
    _speed.setY(rand()%200 - 100);
}

void Mine::draw(QPainter &painter) {
    QPolygon mine;

    mine.append(QPoint(_position.x(), _position.y()+(60/_size)));
    mine.append(QPoint(_position.x()-(15/_size), _position.y()+(7/_size)));
    mine.append(QPoint(_position.x()-(45/_size), _position.y()-(30/_size)));
    mine.append(QPoint(_position.x(), _position.y()-(7/_size)));
    mine.append(QPoint(_position.x()+(45/_size), _position.y()-(30/_size)));
    mine.append(QPoint(_position.x()+(15/_size), _position.y()+(7/_size)));

    painter.drawPolygon(mine);
}

void Mine::mineSpawn(){

}

void Mine::mineMove(){
    //QPoint position = this->position;
    //this->position = QPoint(position.x()+this->moveX,position.y()+this->moveY);
    //painter.drawPolygon(this->mine); //Si on met painter en parametres
}

void Mine::mineEclose(){

}
