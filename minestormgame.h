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
     * @param size : taille de la zone de jeu
     * @param parent : QWidget parent
     */
    MineStormGame(const QSize &size, QObject *parent = nullptr);

    /**
     * @brief draw
     * @param painter
     */
    virtual void draw(QPainter &painter);

    /**
     * @brief Appelée lorsqu'une touche est appuyée
     * @param key : touche pressée
     */
    void keyPressed( int key );

    /**
     * @brief Appelée lorsqu'une touche est relâchée
     * @param key : touche relâchée
     */
    void keyReleased( int key );

    /**
     * @brief Permet de générer des mines disposées aléatoirement
     * @param small : Nombre de petites mines
     * @param medium : Nombre de mines moyennes
     * @param big : Nombre de grandes mines
     */
    void generateMines(int small, int medium, int big);

    /**
     * @brief Décrémente le compteur de vie si il en reste, sinon Game Over
     */
    void looseLife();

private:
    /**
     * @brief Initialise le jeu
     */
    void initialize();

    /**
     * @brief Rajoute de mines (appelé toutes les 30 secondes)
     */
    void repop();

    /**
     * @brief Ajoute une Bullet à l'affichage
     */
    void fire();

    /**
     * @brief Renvoie un point aléatoire à l'écran
     * @return QPoint aléatoire
     */
    QPoint getRandomPoint() const;

    /**
     * @brief Dessine les vies restantes à l'écran
     * @param painter
     */
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
    int _cooldownRespawn;
};

#endif // MINESTORMGAME_H
