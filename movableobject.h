#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QPoint>
#include <QPainter>
#include <math.h>
#include<iostream>
/**
 * @brief La classe MovableObject est une classe mère caractérisant les différents objets qui peuvent se mouvoir dans le jeu
 */
class MovableObject
{
public:
    /**
     * @brief Constructeur de MovableObject
     * @param position : définie la position du MovableObject dans le jeu
     * @param speed : vitesse du MovableObject
     * @param direction : direction du MovableObject
     */
    MovableObject(QPoint position = QPoint(120, 120), int speed = 0, int direction = 0);


    /**
     * @brief Méthode virtuelle pure d'affichage des MovableObjects
     * @param painter : painter servant à peindre le MovableObject sur l'espace de jeu
     */
    virtual void draw(QPainter &painter) = 0;

    /**
     * @brief Retourne la position actuelle du MovableObject
     * @return la position sous forme de QPoint
     */
    QPoint getPosition();

    /**
     * @brief Permet de définir la vitesse du MovableObject
     * @param La nouvelle vitesse du MovableObject
     */
    void setSpeed(int speed);

    /**
     * @brief Retourne la vitesse du MovableObject
     * @return La vitesse de l'objet
     */
    int getSpeed();


    /**
     * @brief Permet de définir la direction de l'objet
     * @param Angle à appliquer sur le MovableObject en radian
     */
    void setDirection(int angle);

    /**
     * @brief Retourne la direction que prend actuellement le MovableObject
     * @return La direction prise
     */
    int getDirection();

    /**
     * @brief Permet de bouger le MovableObject
     * @param Objet QSize permettant de bouger l'objet
     */
    void move(QSize bounds);

    /**
     * @brief Retourne l'existence d'une intersection entre deux MovableObjects
     * @param Le deuxième MovableObject
     * @return Vrai s'il existe une intsection, sinon faux
     */
    virtual bool inContact(MovableObject const &object) const;

    /**
     * @brief Retourne le QPolygon du MovableObject
     * @return Le QPolygon
     */
    virtual QPolygon getPolygon() const = 0;

protected:
    QPoint _position;
    int _direction;
    QPoint _speed;

private:
};

#endif // MOVABLEOBJECT_H
