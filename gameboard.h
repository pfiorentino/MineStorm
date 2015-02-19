#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "scorecontroller.h"

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

class Game;
/**
 * @brief La classe GameBoard définit un widget permettant l'affichage du jeu. Elle gère également les évènements clavier
 */
class GameBoard : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief constructeur du GameBoard
     * @param game partie en cours
     * @param parent
     */
    explicit GameBoard(Game *game, QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent ( QKeyEvent * event );
    void keyReleaseEvent ( QKeyEvent * event );

private:
    QPen _pen;
    Game *_game;
    ScoreController *_scoreController;
};

#endif // GAMEBOARD_H
