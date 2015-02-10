#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H
#include "game.h"

#include <vector>
#include<tuple>
#include "spaceship.h"
#include "mine.h"
#include "explosion.h"

class MineStormGame : public Game
{
    Q_OBJECT
public:
    MineStormGame(const QSize &size, QObject *parent = nullptr);
    virtual void draw(QPainter &painter);
    void keyPressed( int key );
    void keyReleased( int key );
    void generateMines(int small, int medium, int big);
    void looseLife();

private slots:
    void keyboardUpdate();

private:
    void initialize();
    QPoint getRandomPoint();
    void drawLives(QPainter &painter);

    SpaceShip *_ship;
    std::vector<ShipBullet> _bullets;
    std::vector<Mine> _mines;
    std::vector<Explosion> _explosions;
    int _livesLeft;

    void fire();
    bool _leftKeyDown;
    bool _rightKeyDown;
    bool _upKeyDown;
    bool _downKeyDown; //Touche de test, à enlever dans la version finale
    bool _spaceKeyDown;
};

#endif // MINESTORMGAME_H
