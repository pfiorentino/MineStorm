#include "mainwindow.h"
#include "gameboard.h"
#include "scorecontroller.h"

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

    auto score = new ScoreController(game, gameboard);


//    auto layout = new QVBoxLayout;
//    layout->addWidget(gameboard);

//    window->setLayout(layout);
    setCentralWidget(window);
    show();
}

MainWindow::~MainWindow() {
}
