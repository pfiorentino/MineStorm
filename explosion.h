#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QPainter>

/**
 * @brief La classe Explosion gère la définition et l'affichage des explosions
 */

class Explosion
{
public:
    /**
     * @brief Constructeur
     *
     * Constructeur de la classe Explosion
     *
     * @param size : taille souhaitée de l'explosion
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
     * @brief Renvoie le QPolygon représentant l'explosion
     * @return le QPolygon
     */
    QPolygon getPolygon();

    /**
     * @brief Vérifie si l'explosion a atteint sa taille maximale en vue de l'effacer de l'écran
     * @return true si la taille finale est atteinte, false sinon
     */
    bool toRemove() const;
private:
    int _currentSize;
    int _maxSize; /* Taille finale de l'explosion */
    QPoint _position;
    QPoint getAbsolutePoint(QPoint relativePoint) const;
};

#endif // EXPLOSION_H
