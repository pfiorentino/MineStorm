#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>
#include "movableobject.h"


/**
 * @brief La classe Mine hérite de MovableObject et gère la création et l'affichage des mines
 */
class Mine : public MovableObject {
public:
    /**
     * @brief Constructeur de mine
     * @param size : diviseur de la taille de référence de la mine (2 pour diviser la taille par 2, 3 pour 3, etc...)
     * @param position : position actuelle de la mine
     * @param speed : vitesse actuelle de la mine
     * @param direction : sens de déplacement de la mine
     */
    Mine(int size, QPoint position, int speed, int direction);

    /**
     * @brief Méthode d'affichage
     * @param painter
     */
    void draw(QPainter &painter);

    /**
     * @brief Retourne le QPolygon représentant la mine
     * @return le QPolygon
     */
    QPolygon getPolygon() const;

    /**
     * @brief Permet de savoir si la mine a éclos
     * @return true si éclose, false sinon
     */
    bool isBorn();

    /**
     * @brief Permet de connaitre la taille de la Mine
     * @return le diviseur de taille
     */
    int getSize();


private:
    int _size;
    int _eclosionTime;
};

#endif // MINE_H
