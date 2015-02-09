#include "mine.h"

#include <QPolygon>


Mine::Mine(int size, QPoint position, int speed, int direction):MovableObject(position, speed, direction), _size(size) {
    this->_born=false;
}

void Mine::draw(QPainter &painter) {
    if(_born)
        painter.drawPolygon(this->getPolygon());
    else
        painter.drawPoint(this->_position);
}

void Mine::spawn(){

}

void Mine::move(){
    if(!_born) {

    }
    else {
        _position.setX(_position.x()+_speed.x());
        _position.setY(_position.y()+_speed.y());

        if (_position.x() < 0){
            _position.setX(_position.x()+400);
        }
        else if (_position.x() > 400) {
            _position.setX(_position.x()-400);
        }

        if (_position.y() < 0){
            _position.setY(_position.y()+600);
        }
        else if (_position.y() > 600) {
            _position.setY(_position.y()-600);
        }
    }
}

void Mine::eclose(){

}

void Mine::explode(){
    //std::cout<<"La mine explose !"<<std::endl;
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

bool Mine::getBorn() {
    return _born;
}

void Mine::setBorn(bool born) {
    _born=born;
}
