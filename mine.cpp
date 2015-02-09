#include "mine.h"

#include <QPolygon>


Mine::Mine(int size, QPoint position): _size(size), _position(position) {
    _speed.setX(rand()%200 - 100);
    _speed.setY(rand()%200 - 100);
}

Mine::Mine(int size, QPoint position, int speed, int orientation):MovableObject(position, speed, orientation) {
    this->_size = size;
}

void Mine::draw(QPainter &painter) {
    painter.drawPolygon(this->getPolygon());
}

void Mine::spawn(){

}

void Mine::move(){

}

void Mine::eclose(){

}

void Mine::explode(){
    std::cout<<"La mine explose !"<<std::endl;
}

QPolygon Mine::getPolygon(){
    QPolygon mine;

    mine.append(QPoint(_position.x(), _position.y()+(60/_size)));
    mine.append(QPoint(_position.x()-(15/_size), _position.y()+(7/_size)));
    mine.append(QPoint(_position.x()-(45/_size), _position.y()-(30/_size)));
    mine.append(QPoint(_position.x(), _position.y()-(7/_size)));
    mine.append(QPoint(_position.x()+(45/_size), _position.y()-(30/_size)));
    mine.append(QPoint(_position.x()+(15/_size), _position.y()+(7/_size)));

    return mine;
}
