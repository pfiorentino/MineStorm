#ifndef LIFE_H
#define LIFE_H

#include <QPainter>
#include<iostream>

/**
 * @brief La classe Life gère la construction et l'affichage de l'objet "vie" du jeu (vaisseau miniature)
 */
class Life
{
public:
    /**
     * @brief Constructeur
     * @param position
     */
    Life(QPoint position);

    /**
     * @brief Méthode d'affichage
     * @param painter
     */
    void draw(QPainter &painter);

private:
    QPoint _position;
};

#endif // LIFE_H
