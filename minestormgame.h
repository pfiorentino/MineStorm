#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H
#include "game.h"
#include "spaceship.h"

class MineStormGame : public Game
{
    Q_OBJECT
public:
    MineStormGame(QObject *parent = nullptr);
    virtual void draw(QPainter &painter, QRect &rect);
    void keyPressed( int key );
    void keyReleased( int key );
private:
    void initialize();
    SpaceShip _ship;
};

#endif // MINESTORMGAME_H
