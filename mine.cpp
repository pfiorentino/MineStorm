#include "mine.h"

#include <QPolygon>


Mine::Mine(int size, QPoint position, int speed, int direction):
    MovableObject(position, speed, direction), _size(size), _born(false) {
    _eclosionTime = rand()%500+5;
}

void Mine::draw(QPainter &painter) {
    if(_born)
        painter.drawPolygon(this->getPolygon());
    else
        painter.drawPoint(this->_position);
}

void Mine::spawn(){

}

void Mine::eclose() {
    if (_eclosionTime > 0) {
        _eclosionTime--;
    } else if (!_born) {
        _born = true;
    }
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

bool Mine::isBorn() {
    return _born;
}

void Mine::setBorn(bool born) {
    _born = born;
}

int Mine::getSize() {
    return _size;
}
