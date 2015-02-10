#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "scorecontroller.h"

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

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
    QPen _pen;
    Game *_game;
    QLabel *_startLabel;
    ScoreController *_scoreController;
};

#endif // GAMEBOARD_H
