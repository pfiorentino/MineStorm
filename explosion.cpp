#include "explosion.h"

Explosion::Explosion(int size, QPoint position):_size(size), _position(position) {

}

Explosion::~Explosion() {

}

void Explosion::draw(QPainter &painter) {
    QPainterPath path;
    path.addPolygon(this->getPolygon());
    painter.drawPath(path);
}

QPolygon Explosion::getPolygon(){
    QPolygon explosion;

    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, 16)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(6, 10)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(18, 6)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(12, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(8, 4)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(6, -14)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, -12)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-6, -8)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-16, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-12, 8)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-2, 4)));

    return explosion;
}

QPoint Explosion::getAbsolutePoint(QPoint relativePoint) const {
    return QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());
}
