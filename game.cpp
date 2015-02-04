#include "game.h"

Game::Game(QObject *parent):QObject(parent), _isRunning(false){
    _timer.setSingleShot(false);
    connect(&_timer,SIGNAL(timeout()),this,SLOT(update()));
}

void Game::start() {
    //_timer.start( 100 - _speed +1);
    _isRunning = true;
}

void Game::pause(){
    //_timer.stop();
    _isRunning = false;

}

void Game::reset(){
    pause();
    initialize();
    emit changed();
}

void Game::update() {
    if( _isRunning == true ) {
        emit changed();
    }
}

bool Game::isRunning() const {
    return _isRunning;
}

int Game::getScore() const {
    return _score;
}

void Game::setScore(int score) {
    _score = score;
}
