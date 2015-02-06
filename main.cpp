#include "mainwindow.h"
#include "minestormgame.h"

#include <iostream>
#include <QFontDatabase>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

int main(int argc, char *argv[])
{
    QFontDatabase::addApplicationFont(":/fonts/PressStart2P.ttf");

    QApplication a(argc, argv);

    MineStormGame game;
    MainWindow mainWindow(&game);

    // Permet de centrer la fenêtre principale à l'écran
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-mainWindow.width()) / 2;
    int y = (screenGeometry.height()-mainWindow.height()) / 2;
    mainWindow.move(x, y);

    return a.exec();
}
