#include "mainwindow.h"
#include "gameboard.h"
#include "game.h"

#include <QPalette>

MainWindow::MainWindow(Game *game, QWidget *parent) : QMainWindow(parent) {
    this->setMaximumSize(game->size());
    this->setMinimumSize(game->size());

    auto window = new QWidget(this);
    window->setAutoFillBackground(true);
    window->setFixedSize(game->size());

    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::black);
    window->setPalette(pal);

    auto gameboard = new GameBoard(game, window);
    gameboard->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);

    setCentralWidget(window);
    show();
}

MainWindow::~MainWindow() {
}
