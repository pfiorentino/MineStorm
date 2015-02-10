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
    _scoreLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    _scoreLabel->setFont(QFont("Press Start 2P", 17));
    _scoreLabel->resize(140, 40);
}

void ScoreController::refresh() {
    QString text = QString::number(_game->getScore());

    for (int i = text.length(); i < 6; ++i) {
        text.insert(0, '0');
    }

    _scoreLabel->setText(text);
}

