#include "mainwindow.h"
#include "gameboard.h"

#include <QPalette>
#include <QFont>
#include <QLabel>

MainWindow::MainWindow(Game *game, QWidget *parent) : QMainWindow(parent) {
    auto window = new QWidget(this);
    window->setAutoFillBackground(true);
    window->setFixedSize(400, 600);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::black);
    window->setPalette(pal);

    auto gameboard = new GameBoard(game, window);
    gameboard->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);

    QLabel *scoreLabel = new QLabel(gameboard);
    scoreLabel->setContentsMargins(10, 10, 10, 10);
    scoreLabel->setStyleSheet("QLabel { color : rgb(220, 220, 220); }");
    scoreLabel->setText("13 000");
    scoreLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    scoreLabel->setFont(QFont("Press Start 2P", 15));

//    auto layout = new QVBoxLayout;
//    layout->addWidget(gameboard);

//    window->setLayout(layout);
    setCentralWidget(window);
    show();
}

MainWindow::~MainWindow() {
}
