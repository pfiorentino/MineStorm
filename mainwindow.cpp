#include "mainwindow.h"
#include "gameboard.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto window = new QWidget(this);

    auto gameboard = new GameBoard(window);
    gameboard->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding);


    auto layout = new QVBoxLayout;
    layout->addWidget(gameboard);

    window->setLayout(layout);
    setCentralWidget(window);
    show();
}

MainWindow::~MainWindow() {
}
