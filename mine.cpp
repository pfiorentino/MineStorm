#include "mine.h"

#include <QPolygon>

Mine::Mine(int size,int x,int y): _size(size)
{
    this->position = QPoint(x,y);
    this->moveX = rand()%200 - 100; //Vitesse random entre -100 et 100  sur l'axe X
    this->moveY = rand()%200 - 100;
}

Mine::~Mine()
{

}

void Mine::draw(QPainter &painter) {
    QPoint position = this->position;
    this->mine.append(QPoint(position.x(), position.y()+(60/_size)));
    this->mine.append(QPoint(position.x()-(15/_size), position.y()+(7/_size)));
    this->mine.append(QPoint(position.x()-(45/_size), position.y()-(30/_size)));
    this->mine.append(QPoint(position.x(), position.y()-(7/_size)));
    this->mine.append(QPoint(position.x()+(45/_size), position.y()-(30/_size)));
    this->mine.append(QPoint(position.x()+(15/_size), position.y()+(7/_size)));

    painter.drawPolygon(this->mine);
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
