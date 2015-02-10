#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QTimer>
#include <QSize>
class QPainter;
class QRect;

/**
 * @brief La classe Game est une classe abstraite représentant base d'un jeu.
 *  Elle fournit les services de base pour controler un jeu :
 *  - start/pause/reset
 *  - gestion des évènements souris
 *  - gestion des évènements clavier
 *  - gestion de l'affichage
 */
class Game: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Game contruit un jeu
     * @param size taille de la grille de jeu
     * @param parent
     */
    Game(const QSize &size, QObject *parent);
    /**
     * @brief start démarre le jeu
     */
    void start();
    /**
     * @brief pause met le jeu en pause
     */
    void pause();
    /**
     * @brief reset stop le jeu et le réinitialise
     */
    void reset();

    int getScore() const;
    void setScore(int score);

    /**
     * @brief size retourne la taille du jeu
     * @return
     */
    const QSize &size() const;

    /**
     * @brief draw appelée pour afficher le jeu. Cette méthode doit être implémentée par les classes dérivées
     * @param painter context d'affichage voir [la documentation Qt](http://doc.qt.io/qt-5/qpainter.html)
     * @param size taille de la zone dans laquelle peindre le jeu
     */
    virtual void draw(QPainter &painter) = 0;

    /**
     * @brief keyPressed  appélée quand l'utilisateur presse une touche
     * @param key code de la touche. Tous les codes sont disponible dans [la documentation Qt](http://doc.qt.io/qt-5/qt.html#Key-enum)
     *
     */
    virtual void keyPressed( int key ) = 0;
    /**
     * @brief keyReleased  appélée quand l'utilisateur relache une touche
     * @param key code de la touche. Tous les codes sont disponible dans [la documentation Qt](http://doc.qt.io/qt-5/qt.html#Key-enum)
     *
     */
    virtual void keyReleased( int key ) = 0;

    /**
     * @brief isRunning retourne true si le jeu est lancé
     * @return
     */
    bool isRunning() const;

    bool started() const;
protected:
    /**
     * @brief initialize initialise ou réinitialise le jeu
     */
    virtual void initialize() = 0;
    int _score;

signals:
    void changed();

private slots:
    void update();

private:
    QSize _size;
    QTimer _timer;
    QTimer _keyboardTimer;
    bool _started;
    bool _isRunning;
};

#endif // GAME_H
