#include "gameboard.h"
#include "game.h"

#include <QPainter>
#include <QColor>
#include <QLabel>
#include <QMouseEvent>

#include <iostream>

GameBoard::GameBoard(Game *game, QWidget *parent) : QWidget(parent), _game(game) {
    connect(_game,SIGNAL(changed()),this,SLOT(update()));
    setMinimumSize(400,600);
    setFocusPolicy(Qt::StrongFocus);


    _scoreController = new ScoreController(_game, this);
    _scoreController->hide();

    _startLabel = new QLabel(this);
    _startLabel->setStyleSheet("QLabel { color : rgb(220, 220, 220); }");
    _startLabel->setText("Press Enter To Play");
    _startLabel->setAlignment(Qt::AlignCenter);
    _startLabel->setFont(QFont("Press Start 2P", 15));
    _startLabel->resize(400, 30);
    _startLabel->move(0, (this->height()-_startLabel->height())/2);
    _startLabel->show();
}

void GameBoard::paintEvent(QPaintEvent * /* event */ ) {
    QPainter painter;
    painter.begin(this);

    QPen pen = QPen(QColor(220,220,220));
    pen.setWidth(2);
    painter.setPen(pen);

    if (_game->started()){
        _scoreController->show();
        _startLabel->hide();
        _game->draw(painter);
    } else {
        _scoreController->hide();
        _startLabel->setText("Press Enter To Play");
        _startLabel->show();
    }

    painter.end();
}

void GameBoard::keyPressEvent ( QKeyEvent * event ) {
    _game->keyPressed(event->key());
}
void GameBoard::keyReleaseEvent ( QKeyEvent * event ) {
    _game->keyReleased(event->key());
}
