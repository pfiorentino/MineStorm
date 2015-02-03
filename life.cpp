#include "life.h"

#include <QPolygon>

Life::Life()
{

}

void Life::draw(QPainter &painter, QPoint position) {
    QPolygon ship;

    ship.append(QPoint(position.x()-5, position.y()));
    ship.append(QPoint(position.x()-5, position.y()+5));
    ship.append(QPoint(position.x(), position.y()));
    ship.append(QPoint(position.x()+1, position.y()-1));
    ship.append(QPoint(position.x(), position.y()-10));
    ship.append(QPoint(position.x()-1, position.y()-1));
    ship.append(QPoint(position.x(), position.y()));
    ship.append(QPoint(position.x()+5, position.y()+5));
    ship.append(QPoint(position.x()+5, position.y()));

    QPainterPath path;
    path.addPolygon(ship);

    painter.drawPath(path);
}

