#include "overlaytext.h"
#include "game.h"

OverlayText::OverlayText(Game *game, QWidget *parent) : QWidget(parent), _game(game) {
    connect(_game,SIGNAL(changed()),this,SLOT(update()));
    setMinimumSize(_game->size());

    _label = new QLabel(parent);
    _label->setStyleSheet("QLabel { color : rgb(220, 220, 220); }");
    _label->setAlignment(Qt::AlignCenter);
    _label->setFont(QFont("Press Start 2P", 15));
    _label->resize(parent->width(), 30);
    _label->move(0, (parent->height()-_label->height())/2);
    _label->show();

    show();
}

void OverlayText::paintEvent(QPaintEvent * /* event */ ) {
    if (_game->isOver()){
        _label->setText("Game Over");
    } else if (!_game->started()){
        _label->setText("Press Enter To Play");
    } else if (!_game->isRunning()) {
        _label->setText("Pause");
    } else {
        _label->setText("");
    }
}

