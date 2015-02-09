#include "game.h"

Game::Game(const QSize &size, QObject *parent):QObject(parent), _size(size), _isRunning(false){
    _timer.setSingleShot(false);
    connect(&_timer,SIGNAL(timeout()),this,SLOT(update()));
}

const QSize &Game::size() const {
    return _size;
}

void Game::start() {
    _timer.start(30);
    _isRunning = true;
    _started = true;
}

void Game::pause(){
    _timer.stop();
    _isRunning = false;
}

void Game::reset(){
    pause();
    _started = false;
    initialize();
    emit changed();
}

void Game::update() {
    emit changed();
}

bool Game::isRunning() const {
    return _isRunning;
}

bool Game::started() const {
    return _started;
}

int Game::getScore() const {
    return _score;
}

void Game::setScore(int score) {
    _score = score;
}
