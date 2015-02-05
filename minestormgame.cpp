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

    _ship.draw(painter);

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
}

void MineStormGame::initialize() {
    Game::_score = 0;
}

void MineStormGame::keyPressed( int key ) {
    switch(key) {
        case Qt::Key_Left:
            _ship.turnLeft();
            emit changed();
            break;
        case Qt::Key_Right:
            _ship.turnRight();
            Game::_score = _ship.getAngle();
            emit changed();
            break;
    }
}
void MineStormGame::keyReleased( int key ) {
}


