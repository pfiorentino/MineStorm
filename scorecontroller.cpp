#include "scorecontroller.h"
#include "game.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QFont>

ScoreController::ScoreController(Game *game, QWidget *parent) : QWidget(parent),_game(game)
{
    connect(_game,SIGNAL(changed()),this,SLOT(refresh()));

    _scoreLabel = new QLabel(this);
    _scoreLabel->setContentsMargins(10, 10, 10, 10);
    _scoreLabel->setStyleSheet("QLabel { color : rgb(220, 220, 220); }");
    _scoreLabel->setText("0");
    _scoreLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    _scoreLabel->setFont(QFont("Press Start 2P", 15));
}

void ScoreController::refresh() {
    _scoreLabel->setText(QString::number(_game->getScore()));
}

