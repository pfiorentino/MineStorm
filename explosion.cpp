#include "explosion.h"

Explosion::Explosion(int size, QPoint position):
    _currentSize(1), _maxSize(size), _position(position) {
}

Explosion::~Explosion() {

}

void Explosion::draw(QPainter &painter) {
    if (_currentSize < _maxSize)
        ++_currentSize;

    QPainterPath path;
    path.addPolygon(this->getPolygon());
    painter.drawPath(path);
}

QPolygon Explosion::getPolygon(){
    QPolygon explosion;

    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(1, -8)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(3, -5)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(9, -3)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(6, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(4, -2)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(3, 7)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, 6)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-3, 4)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-8, 0)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-6, -4)));
    explosion.append(getAbsolutePoint(QPoint(0, 0)));
    explosion.append(getAbsolutePoint(QPoint(-1, -2)));

    return explosion;
}

QPoint Explosion::getAbsolutePoint(QPoint relativePoint) const {
    return QPoint(_position.x()+(relativePoint.x()*_currentSize), _position.y()+(relativePoint.y()*_currentSize));
}

bool Explosion::toRemove() const {
    return _currentSize == _maxSize;
}
