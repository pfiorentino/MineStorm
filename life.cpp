#include "life.h"

#include <QPolygon>

Life::Life(QPoint position):
    _position(position) {
}

void Life::draw(QPainter &painter) {
    QPolygon life;

    life.append(QPoint(_position.x()-5, _position.y()));
    life.append(QPoint(_position.x()-5, _position.y()+5));
    life.append(QPoint(_position.x(), _position.y()));
    life.append(QPoint(_position.x()+1, _position.y()-1));
    life.append(QPoint(_position.x(), _position.y()-10));
    life.append(QPoint(_position.x()-1, _position.y()-1));
    life.append(QPoint(_position.x(), _position.y()));
    life.append(QPoint(_position.x()+5, _position.y()+5));
    life.append(QPoint(_position.x()+5, _position.y()));

    QPainterPath path;
    path.addPolygon(life);

    painter.drawPath(path);
}


