#include "minestormgame.h"
#include "mine.h"
#include "life.h"

#include <QPainter>
#include <QRect>
#include <QColor>

#include <iostream>

MineStormGame::MineStormGame(QObject *parent):Game(parent)
{
    initialize();
}

void MineStormGame::draw(QPainter &painter, QRect &rect) {
    _ship->move();

    if (_upKeyDown)
        _ship->accelerate();
    if (_leftKeyDown)
        _ship->turnLeft();
    if (_rightKeyDown)
        _ship->turnRight();

    _ship->draw(painter);

    Life life;
    life.draw(painter, QPoint(380, 580));
    life.draw(painter, QPoint(365, 580));
    life.draw(painter, QPoint(350, 580));

    Mine mine(1, QPoint(100,400));
    mine.draw(painter);

    Mine mineMed(2, QPoint(50,250));
    mineMed.draw(painter);

    Mine mineSmall(4, QPoint(250,250));
    mineSmall.draw(painter);

    Game::_score = _ship->getSpeed();
}

void MineStormGame::initialize() {
    _ship = new SpaceShip();
    Game::_score = 0;
    _upKeyDown = false;
    _leftKeyDown = false;
    _rightKeyDown = false;
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
            //_ship.accelerate();
            _upKeyDown = true;
            break;
        case Qt::Key_Return:
            Game::start();
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
            break;
    }
}


