#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H

#include <QWidget>
#include <QLabel>

class Game;
/**
 * @brief La classe ScoreController gère l'affichage du score
 */
class ScoreController : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param game
     * @param parent
     */
    explicit ScoreController(Game *game, QWidget *parent = 0);

signals:

public slots:
    void refresh();

private:
    Game *_game;
    QLabel *_scoreLabel;
};

#endif // SCORECONTROLLER_H
