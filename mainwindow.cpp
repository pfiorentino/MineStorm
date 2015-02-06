#include "mainwindow.h"
#include "gameboard.h"

#include <QPalette>

MainWindow::MainWindow(Game *game, QWidget *parent) : QMainWindow(parent) {
    auto window = new QWidget(this);
    window->setAutoFillBackground(true);
    window->setFixedSize(400, 600);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::black);
    window->setPalette(pal);

    auto gameboard = new GameBoard(game, window);
    gameboard->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);

    setCentralWidget(window);
    show();
}

MainWindow::~MainWindow() {
}
