#ifndef MINESTORMGAME_H
#define MINESTORMGAME_H
#include "game.h"

#include <vector>
#include<tuple>
#include "spaceship.h"
#include "mine.h"
#include "explosion.h"

/**
 * @brief La classe MineStormGame gère l'ensemble du jeu et centralise les actions
 */
class MineStormGame : public Game {
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param size
     * @param parent
     */
    MineStormGame(const QSize &size, QObject *parent = nullptr);
    /**
     * @brief draw
     * @param painter
     */
    virtual void draw(QPainter &painter);
    /**
     * @brief Teste l'appuie sur une touche
     * @param key la touche testée
     */
    void keyPressed( int key );
    /**
     * @brief Teste le relachement de la touche
     * @param key la touche testée
     */
    void keyReleased( int key );
    /**
     * @brief Création des mines
     * @param small Nombre de petites mines
     * @param medium Nombre de mines moyennes
     * @param big Nombre de grandes mines
     */
    void generateMines(int small, int medium, int big);
    /**
     * @brief Decremente le nombre de vie si il en reste, sinon Game Over
     */
    void looseLife();

private:
    void initialize();
    void repop();
    void fire();

    QPoint getRandomPoint() const;
    void drawLives(QPainter &painter) const;

    SpaceShip *_ship;

    std::vector<ShipBullet> _bullets;
    std::vector<Mine> _mines;
    std::vector<Explosion> _explosions;

    int _livesLeft;

    bool _leftKeyDown;
    bool _rightKeyDown;
    bool _upKeyDown;
    bool _downKeyDown; //Touche de test, à enlever dans la version finale
    bool _spaceKeyDown;

    int _fireCounter;
    int _accelerationFactor;
    int _repopCounter;
};

#endif // MINESTORMGAME_H
