#include "gameboard.h"
#include "game.h"

#include <QColor>

GameBoard::GameBoard(Game *game, QWidget *parent) : QWidget(parent), _game(game) {
    connect(_game,SIGNAL(changed()),this,SLOT(update()));

    setMinimumSize(_game->size());
    setFocusPolicy(Qt::StrongFocus);

    _pen = QPen(QColor(220,220,220));
    _pen.setWidth(2);

    _scoreController = new ScoreController(_game, this);
}

void GameBoard::paintEvent(QPaintEvent * /* event */ ) {
    if (_game->started()){
        QPainter painter;
        painter.begin(this);
        painter.setPen(_pen);

        _game->draw(painter);
        _scoreController->show();

        painter.end();
    } else {
        _scoreController->hide();
    }
}

void GameBoard::keyPressEvent ( QKeyEvent * event ) {
    _game->keyPressed(event->key());
}
void GameBoard::keyReleaseEvent ( QKeyEvent * event ) {
    _game->keyReleased(event->key());
}
