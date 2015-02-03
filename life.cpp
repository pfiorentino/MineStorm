#include "life.h"

#include <QPolygon>

Life::Life()
{

}

void Life::draw(QPainter &painter, QPoint position) {
    QPolygon life;

    life.append(QPoint(position.x()-5, position.y()));
    life.append(QPoint(position.x()-5, position.y()+5));
    life.append(QPoint(position.x(), position.y()));
    life.append(QPoint(position.x()+1, position.y()-1));
    life.append(QPoint(position.x(), position.y()-10));
    life.append(QPoint(position.x()-1, position.y()-1));
    life.append(QPoint(position.x(), position.y()));
    life.append(QPoint(position.x()+5, position.y()+5));
    life.append(QPoint(position.x()+5, position.y()));

    QPainterPath path;
    path.addPolygon(life);

    painter.drawPath(path);
}

