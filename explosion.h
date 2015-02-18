#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QPainter>

/**
 * @brief Classe gérant les explosions
 */

class Explosion
{
public:
    /**
     * @brief Constructeur
     *
     * Constructeur de la classe Explosion
     *
     * @param size : taille de l'explosion
     * @param position : position du centre sur l'écran
     */
    Explosion(int size, QPoint position);

    /**
     * @brief Destructeur
     *
     * Destructeur de la classe Explosion
     *
     */
    ~Explosion();

    /**
     * @brief Méthode d'affichage
     * @param painter
     */
    void draw(QPainter &painter);

    /**
     * @brief Getter de polygon
     * @return Renvoie le QPolygon
     */
    QPolygon getPolygon();

    /**
     * @brief Méthode test de la taille
     * @return True si la taille actuelle est la taille max, False sinon
     */
    bool toRemove() const;
private:
    int _currentSize; /*!
    int _maxSize; /*!< Taille maximale de l'explosion */
    QPoint _position;
    /**
     * @brief Récupération de position
     * @param relativePoint : point à tester
     * @return La position du point selon la taille actuelle de l'explosion
     */
    QPoint getAbsolutePoint(QPoint relativePoint) const;
};

#endif // EXPLOSION_H
