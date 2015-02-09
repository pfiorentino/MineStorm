#include "minestormgame.h"
#include "life.h"

#include <QPainter>
#include <QRect>
#include <QColor>

#include <iostream>
#include <random>

MineStormGame::MineStormGame(const QSize &size, QObject *parent):Game(size, parent) {
    initialize();
}

void MineStormGame::generateMines(int small, int medium, int big) {

    for (int i = 0; i<small; i++) {
        Mine mine(4, getRandomPoint(),rand()%5 +2,rand()%360);
        _mines.push_back(mine);
    }
    for (int i = 0; i<medium; i++) {
        Mine mine(2, getRandomPoint(),rand()%5 +2,rand()%360);
        _mines.push_back(mine);
    }
    for (int i = 0; i<big; i++) {
        Mine mine(1, getRandomPoint(),rand()%5 +2,rand()%360);
        _mines.push_back(mine);
    }
}

void MineStormGame::draw(QPainter &painter) {
    _ship->move(size());

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

    drawLives(painter);

    std::vector<Explosion>::iterator explIt = _explosions.begin();
    while(explIt != _explosions.end()){
        if (explIt->toRemove()){
            explIt = _explosions.erase(explIt);
        } else {
            explIt->draw(painter);
            ++explIt;
        }
    }


    std::vector<ShipBullet>::iterator it = _bullets.begin();
    while(it != _bullets.end()){

        if(it->isAlive()<1){
            it = _bullets.erase(it);
        } else {
            it->move(size());
            it->draw(painter);
            ++it;
        }
    }
    std::vector<Mine>::iterator it2 = _mines.begin();
    bool destroyed = false;
    bool needEclosion = true;
    while(it2 != _mines.end()){
        if (it2->getBorn() == false && needEclosion) {
            it2->setBorn(true);
            needEclosion = false;
        }
        it2->move(size());
        it2->draw(painter);
        it = _bullets.begin();

        if(!it2->getPolygon().intersected(_ship->getPolygonDetection()).isEmpty()){
            it2->explode();
            _ship->explode();

            this->looseLife();
            _ship = new SpaceShip(QPoint(size().width()/2, size().height()/2));
        }
        destroyed = false;

        while(it != _bullets.end()){
            if(!it2->getPolygon().intersected(it->getPolygonDetection()).isEmpty()){
                it2->explode();
                it->explode();
                it = _bullets.erase(it);
                it2 = _mines.erase(it2);

                Explosion expl(8, it2->getPosition());
                _explosions.push_back(expl);

                destroyed = true;
            }
            else{
            ++it;
            }
        }
        if(!destroyed){
            ++it2;
        }
    }
}

void MineStormGame::initialize() {
    _ship = new SpaceShip(QPoint(size().width()/2, size().height()/2));
    _bullets.clear();
    _mines.clear();
    _score = 0;
    _livesLeft = 3;
    _upKeyDown = false;
    _leftKeyDown = false;
    _rightKeyDown = false;
    _downKeyDown = false;
    _spaceKeyDown =false;
    generateMines(0,0,5);
}

QPoint MineStormGame::getRandomPoint() {
    return QPoint(rand()%size().width(),rand()%size().height());
}

void MineStormGame::drawLives(QPainter &painter) {
    for(int i=0; i<_livesLeft; i++){
        Life life(QPoint(size().width()-(20+i*15), size().height()-20));
        life.draw(painter);
    }
}

void MineStormGame::fire() {
    _bullets.push_back(ShipBullet(_ship->getPosition(),18, _ship->getOrientation()));
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
        case Qt::Key_Space:
        case Qt::Key_Control:
            _spaceKeyDown = true;
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
        case Qt::Key_Space:
        case Qt::Key_Control:
            _spaceKeyDown = false;
        break;

    }
}

void MineStormGame::looseLife(){
    this->_livesLeft--;
}


