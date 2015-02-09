#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H
#include "game.h"

#include <vector>
#include<tuple>
#include "spaceship.h"
#include "mine.h"
class MineStormGame : public Game
{
    Q_OBJECT
public:
    MineStormGame(QObject *parent = nullptr);
    virtual void draw(QPainter &painter);
    void keyPressed( int key );
    void keyReleased( int key );
    void generateMine(int small, int medium, int big);
private:
    void initialize();
    SpaceShip *_ship;
    std::vector<ShipBullet> _bullets;
    std::vector<Mine> _mines;
    void fire();
    bool _leftKeyDown;
    bool _rightKeyDown;
    bool _upKeyDown;
    bool _downKeyDown; //Touche de test, à enlever dans la version finale
    bool _spaceKeyDown;
};

#endif // MINESTORMGAME_H
