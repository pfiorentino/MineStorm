#include "minestormgame.h"
#include "spaceship.h"
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
    SpaceShip ship;
    ship.draw(painter, QPoint(200,300));

    Life life;
    life.draw(painter, QPoint(380, 580));
    life.draw(painter, QPoint(365, 580));
    life.draw(painter, QPoint(350, 580));

    Mine mine(1);
    mine.draw(painter, QPoint(100, 400));

    Mine mineMed(2);
    mineMed.draw(painter, QPoint(50, 250));

    Mine mineSmall(4);
    mineSmall.draw(painter, QPoint(250, 250));
}

void MineStormGame::initialize() {
    _score = 0;
}

void MineStormGame::keyPressed( int key ) {
    switch(key) {
    case Qt::Key_1:
        break;
    case Qt::Key_2:
        break;
    case Qt::Key_3:
        break;
    case Qt::Key_4:
        break;
    }
}
void MineStormGame::keyReleased( int key ) {
}

int MineStormGame::getScore() {
    return _score;
}