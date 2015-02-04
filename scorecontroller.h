#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H

#include <QWidget>
#include <QLabel>

class Game;

class ScoreController : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreController(Game *game, QWidget *parent = 0);

signals:

public slots:
    void change();

private:
    Game *_game;
    QLabel *_scoreLabel;
};

#endif // SCORECONTROLLER_H
