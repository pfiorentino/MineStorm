#include "scorecontroller.h"
#include "game.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QFont>

ScoreController::ScoreController(Game *game, QWidget *parent) : QWidget(parent),_game(game)
{
    auto button1 = new QPushButton("Click");

    _scoreLabel = new QLabel();
    _scoreLabel->setContentsMargins(10, 10, 10, 10);
    _scoreLabel->setStyleSheet("QLabel { color : rgb(220, 220, 220); }");
    _scoreLabel->setText("13 000");
    _scoreLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    _scoreLabel->setFont(QFont("Press Start 2P", 15));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(_scoreLabel);

    setLayout(layout);

    connect(button1,SIGNAL(clicked()),this,SLOT(change()));
}

void ScoreController::change() {
    _game->setScore(12);
    _scoreLabel->setText(QString::number(_game->getScore()));
}

