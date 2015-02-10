#include "mainwindow.h"
#include "minestormgame.h"

#include <QFontDatabase>
#include <QApplication>
#include <QDesktopWidget>
#include <QStatusBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase fontDb;
    fontDb.addApplicationFont(":/fonts/PressStart2P.ttf");

    MineStormGame game(QSize(600, 700));
    MainWindow mainWindow(&game);

    // Permet de centrer la fenêtre principale à l'écran
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-mainWindow.width()) / 2;
    int y = (screenGeometry.height()-mainWindow.height()) / 2;
    mainWindow.move(x, y);

    return a.exec();
}
