#include "gameboard.h"

#include <QPainter>
#include <QColor>
#include <QSize>
#include <QMouseEvent>

#include <iostream>

GameBoard::GameBoard(QWidget *parent) : QWidget(parent) {
    setMinimumSize(QSize(400,600));
    setFocusPolicy(Qt::StrongFocus);
}
