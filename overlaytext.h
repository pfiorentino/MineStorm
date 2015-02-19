#ifndef OVERLAYTEXT_H
#define OVERLAYTEXT_H

#include <QWidget>
#include <QPainter>
#include <QLabel>

class Game;
/**
 * @brief La classe OverlayText définit un widget permettant l'affichage de texte par dessus l'écran de jeu comme "Pause" ou "Game Over"
 */
class OverlayText : public QWidget
{
    Q_OBJECT
public:
    explicit OverlayText(Game *game, QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

private:
    Game *_game;
    QLabel *_label;
};

#endif // OVERLAYTEXT_H
