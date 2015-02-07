#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H
#include "game.h"

#include <vector>

#include "spaceship.h"

class MineStormGame : public Game
{
    Q_OBJECT
public:
    MineStormGame(QObject *parent = nullptr);
    virtual void draw(QPainter &painter);
    void keyPressed( int key );
    void keyReleased( int key );
private:
    void initialize();
    SpaceShip *_ship;
    std::vector<ShipBullet> _bullets;
    void fire();
    bool _leftKeyDown;
    bool _rightKeyDown;
    bool _upKeyDown;
    bool _downKeyDown; //Touche de test, à enlever dans la version finale
};

#endif // MINESTORMGAME_H
