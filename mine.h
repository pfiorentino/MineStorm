#ifndef MINE_H
#define MINE_H

#include <QPainter>
#include <QPolygon>
#include "movableobject.h"


/**
 * @brief La classe Mine hérite de MovableObject et gère la gestion des mines
 */
class Mine : public MovableObject {
public:
    /**
     * @brief Constructeur de mine
     * @param size : diviseur de la taille de la mine
     * @param position : position d'apparition de la mine
     * @param speed : vitesse affectée à la mine
     * @param direction : direction de la mine
     */
    Mine(int size, QPoint position, int speed, int direction);

    /**
     * @brief Méthode d'affichage
     * @param painter
     */
    void draw(QPainter &painter);
    /**
     * @brief Renvoie le Qpolygone
     * @return le polygone
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
