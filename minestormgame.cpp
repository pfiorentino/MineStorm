#include "minestormgame.h"
#include "mine.h"
#include "life.h"

#include <QPainter>
#include <QRect>
#include <QColor>

#include <iostream>
#include <random>

MineStormGame::MineStormGame(QObject *parent):Game(parent) {
    initialize();
}

void MineStormGame::generateMine(int small, int medium, int big) {

    for (int i = 0; i<small; i++) {
        Mine mine(4, QPoint(rand()%400,rand()%600),rand()%5 +2,rand()%360);
        _mines.push_back(mine);
    }
    for (int i = 0; i<medium; i++) {
        Mine mine(2, QPoint(rand()%400,rand()%600),rand()%5 +2,rand()%360);
        _mines.push_back(mine);
    }
    for (int i = 0; i<big; i++) {
        Mine mine(1, QPoint(rand()%400,rand()%600),rand()%5 +2,rand()%360);
        _mines.push_back(mine);
    }

}

void MineStormGame::draw(QPainter &painter) {
    _ship->move();

    if (_upKeyDown)
        _ship->accelerate();
    if (_leftKeyDown)
        _ship->rotateLeft();
    if (_rightKeyDown)
        _ship->rotateRight();
    if (_spaceKeyDown)
        fire();

    _score = _ship->getSpeed();
    _ship->draw(painter);

    Life life;
    life.draw(painter, QPoint(380, 580));
    life.draw(painter, QPoint(365, 580));
    life.draw(painter, QPoint(350, 580));




    std::vector<ShipBullet>::iterator it = _bullets.begin();
    while(it != _bullets.end()) {
        if(it->getAlive()<1){
            it = _bullets.erase(it);
        } else {
            it->move();
            it->draw(painter);
            ++it;
        }
    }

    it = _bullets.begin();
    std::vector<Mine>::iterator it2 = _mines.begin();

    while(it2 != _mines.end()){
        it2->move();
        it2->draw(painter);
        while(it != _bullets.end()){
           // std::cout<<"Je passe dans le while bullet"<<std::endl;
            if(!it2->getPolygon().intersected(it->getPolygon()).isEmpty()){
                it2->explode();
                it->explode();
                std::cout<<"Je collisionne"<<std::endl;
            }
            ++it;
        }
        if(!it2->getPolygon().intersected(_ship->getPolygon()).isEmpty()){
            it2->explode();
            _ship->explode();
        }
        ++it2;
    }

}

void MineStormGame::initialize() {
    _ship = new SpaceShip();
    _bullets.clear();
    _mines.clear();
    _score = 0;
    _upKeyDown = false;
    _leftKeyDown = false;
    _rightKeyDown = false;
    _downKeyDown = false;
    _spaceKeyDown =false;
    generateMine(5,5,5);
}

void MineStormGame::fire() {
    _bullets.push_back(ShipBullet(_ship->getPosition(),18, _ship->getOrientation()));
 //   std::cout<<"Fire ! "<<_bullets.size()<<std::endl;

}

void MineStormGame::keyPressed( int key ) {
    switch(key) {
        case Qt::Key_Left:
            _leftKeyDown = true;
            break;
        case Qt::Key_Right:
            _rightKeyDown = true;
            break;
        case Qt::Key_Up:
            _upKeyDown = true;
            break;
        case Qt::Key_Down:
            _downKeyDown = true;
            break;
        case Qt::Key_Space || Qt::Key_Control:
            _spaceKeyDown =true;
            break;
        case Qt::Key_Return:
            if (this->isRunning())
                this->pause();
            else
                this->start();
            break;
        case Qt::Key_Escape:
            Game::reset();
            break;
    }
}

void MineStormGame::keyReleased( int key ) {
    switch(key) {
        case Qt::Key_Left:
            _leftKeyDown = false;
            break;
        case Qt::Key_Right:
            _rightKeyDown = false;
            break;
        case Qt::Key_Up:
            _upKeyDown = false;
            _ship->stopAcceleration();
            break;
        case Qt::Key_Down:
            _downKeyDown = false;
            _ship->stop();
        break;
        case Qt::Key_Space || Qt::Key_Control:
            _spaceKeyDown = false;
        break;

    }
}


