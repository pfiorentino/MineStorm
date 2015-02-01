#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
class Game;
/**
 * @brief La class GameBoard définit un widget permettant l'affichage du jeu. Elle gère également les évènements clavier
 */
class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = 0);

signals:

public slots:


protected:

private:
};

#endif // GAMEBOARD_H
