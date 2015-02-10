#include "mine.h"

#include <QPolygon>


Mine::Mine(int size, QPoint position, int speed, int direction):
    MovableObject(position, speed, direction), _size(size) {
    _eclosionTime = rand()%400+5;
}

void Mine::draw(QPainter &painter) {
    if (_eclosionTime > 0) {
        _eclosionTime--;
        painter.drawPoint(this->_position);
    } else {
        painter.drawPolygon(this->getPolygon());
    }
}

QPolygon Mine::getPolygon() const{
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
    return _eclosionTime <= 0;
}

int Mine::getSize() {
    return _size;
}
