#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "scorecontroller.h"

#include <QWidget>
class Game;
/**
 * @brief La class GameBoard définit un widget permettant l'affichage du jeu. Elle gère également les évènements clavier
 */
class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(Game *game, QWidget *parent = 0);

signals:

public slots:


protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent ( QKeyEvent * event );
    void keyReleaseEvent ( QKeyEvent * event );

private:
    Game *_game;
    ScoreController *_scoreController;
    QLabel *_startLabel;
};

#endif // GAMEBOARD_H
