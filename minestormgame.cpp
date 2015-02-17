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
        Mine mine(3, getRandomPoint(),rand()%5 +2,rand()%360);
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
    --_repopCounter;
    if (_repopCounter == 0)
        repop();

    if (_leftKeyDown)
        _ship->rotateLeft();
    if (_rightKeyDown)
        _ship->rotateRight();
    if (_upKeyDown) {
        _accelerationFactor++;

        if (_accelerationFactor%2 == 0)
            _ship->accelerate();
    }

    if (_spaceKeyDown && !_gameOver)
        fire();

    std::vector<Mine>::iterator mine;
    std::vector<ShipBullet>::iterator bullet = _bullets.begin();
    while(bullet != _bullets.end()){
        bool mineShot = false;
        if(bullet->isAlive()){
            mine = _mines.begin();
            while(mine != _mines.end() && !mineShot){
                if (mine->isBorn() && mine->inContact(*bullet)){
                    _explosions.push_back(Explosion(15/mine->getSize(), mine->getPosition()));
                    _score += 10;

                    mineShot = true;
                    mine = _mines.erase(mine);
                } else {
                    ++mine;
                }
            }

            if  (mineShot){
                bullet = _bullets.erase(bullet);
            } else {
                bullet->move(size());
                bullet->draw(painter);
                ++bullet;
            }
        } else {
            bullet = _bullets.erase(bullet);
        }
    }

    mine = _mines.begin();
    while(mine != _mines.end()){
        if (mine->isBorn() && mine->inContact(*_ship) && !_ship->isInvincible() && !_gameOver){
            _explosions.push_back(Explosion(15, _ship->getPosition()));
            _explosions.push_back(Explosion(15/mine->getSize(), mine->getPosition()));

            _score +=10;
            this->looseLife();

            mine = _mines.erase(mine);
        } else {
            if (mine->isBorn())
                mine->move(size());

            mine->draw(painter);
            ++mine;
        }
    }

    drawLives(painter);

    if (!_gameOver) {
        _ship->move(size());
        _ship->draw(painter);
    }

    std::vector<Explosion>::iterator explosion = _explosions.begin();
    while(explosion != _explosions.end()){
        if (explosion->toRemove()){
            explosion = _explosions.erase(explosion);
        } else {
            explosion->draw(painter);
            ++explosion;
        }
    }
}

void MineStormGame::initialize() {
    _gameOver = false;

    _ship = new SpaceShip(QPoint(size().width()/2, size().height()/2));

    _bullets.clear();
    _mines.clear();
    _explosions.clear();

    _score = 0;
    _livesLeft = 3;

    _fireCounter = 0;
    _accelerationFactor = 0;
    _repopCounter = 1200;

    _upKeyDown = false;
    _leftKeyDown = false;
    _rightKeyDown = false;
    _downKeyDown = false;
    _spaceKeyDown =false;

    generateMines(5,20,5);
}

void MineStormGame::repop() {
    generateMines(1,3,1);
    _repopCounter = 1200;
}

QPoint MineStormGame::getRandomPoint() const {
    return QPoint(rand()%size().width(),rand()%size().height());
}

void MineStormGame::drawLives(QPainter &painter) const {
    for(int i=0; i<_livesLeft; i++){
        Life life(QPoint(size().width()-(20+i*15), size().height()-20));
        life.draw(painter);
    }
}

void MineStormGame::fire() {
    if (_fireCounter%10 == 0){
        _bullets.push_back(ShipBullet(_ship->getPosition(),18, _ship->getOrientation()));
    }

    ++_fireCounter;
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
            if (_gameOver){
                initialize();
            } else if (this->isRunning()) {
                this->pause();
            } else {
                this->start();
            }
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
            _accelerationFactor = 0;
            _ship->stopAcceleration();
            _upKeyDown = false;
            break;
        case Qt::Key_Down:
            _downKeyDown = false;
            _ship->stop();
        break;
        case Qt::Key_Space:
        case Qt::Key_Control:
            _fireCounter = 0;
            _spaceKeyDown = false;
        break;

    }
}

void MineStormGame::looseLife(){
    if (_livesLeft <= 0){
        _gameOver = true;
    } else {
        this->_livesLeft--;
        _ship = new SpaceShip(QPoint(size().width()/2, size().height()/2));
    }
}


