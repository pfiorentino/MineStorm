#include "life.h"

#include <QPolygon>

Life::Life()
{
    _listLife.push_back(QPoint(350,580));
    _listLife.push_back(QPoint(365,580));
    _listLife.push_back(QPoint(380,580));
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

void Life::drawAllLifes(QPainter &painter, int nbLife){
    for(int i =0; i<nbLife;i++){
        this->draw(painter,this->_listLife[i]);
    }

}


