#include "gameboard.h"
#include "game.h"

#include <QPainter>
#include <QColor>
#include <QMouseEvent>

#include <iostream>

GameBoard::GameBoard(Game *game, QWidget *parent) : QWidget(parent), _game(game) {
    connect(_game,SIGNAL(changed()),this,SLOT(update()));
    setMinimumSize(400,600);
    setFocusPolicy(Qt::StrongFocus);
}

void GameBoard::paintEvent(QPaintEvent * /* event */ ) {
    QPainter painter;
    painter.begin(this);
    QPen pen = QPen(QColor(220,220,220));
    pen.setWidth(2);
    painter.setPen(pen);
    auto rectT = rect();
    _game->draw(painter, rectT);
    painter.end();
}

void GameBoard::keyPressEvent ( QKeyEvent * event ) {
    _game->keyPressed(event->key());
}
void GameBoard::keyReleaseEvent ( QKeyEvent * event ) {
    _game->keyReleased(event->key());
}
