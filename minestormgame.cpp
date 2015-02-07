#include "minestormgame.h"
#include "mine.h"
#include "life.h"

#include <QPainter>
#include <QRect>
#include <QColor>

#include <iostream>

MineStormGame::MineStormGame(QObject *parent):Game(parent) {
    initialize();
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

    QPolygon ship = _ship->draw(painter);

    Life life;
    life.draw(painter, QPoint(380, 580));
    life.draw(painter, QPoint(365, 580));
    life.draw(painter, QPoint(350, 580));

    Mine mine(1, QPoint(100,400));
    _listMine.push_back(mine.draw(painter));

    Mine mineMed(2, QPoint(50,250));
    _listMine.push_back(mineMed.draw(painter));

    Mine mineSmall(4, QPoint(250,250));
    _listMine.push_back(mineSmall.draw(painter));

    std::vector<ShipBullet>::iterator it = _bullets.begin();
    while(it != _bullets.end()) {
        if(it->getAlive()<1){
            it = _bullets.erase(it);
         //   _listBullets.pop_front();
        } else {
            it->move();
         //   _listBullets.push_back(it->draw(painter));
            ++it;
        }
    }
}

void MineStormGame::initialize() {
    _ship = new SpaceShip();
    _bullets.clear();
    _score = 0;
    _upKeyDown = false;
    _leftKeyDown = false;
    _rightKeyDown = false;
    _downKeyDown = false;
    _spaceKeyDown =false;
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
        case Qt::Key_Space:
            _spaceKeyDown = false;
        break;

    }
}


