#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Game;
/**
 * @brief La classe MainWindow crée un widget contenant le gameboard pour le jeu donné
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la fenêtre principale
     * @param game : jeu en cours
     * @param parent : Widget parent
     */
    explicit MainWindow(Game *game, QWidget *parent = 0);

    ~MainWindow();

private:
};

#endif // MAINWINDOW_H
