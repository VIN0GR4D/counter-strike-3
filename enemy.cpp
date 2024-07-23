#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy() {
    int random_x = rand() % 700;
    setPos(random_x, 0);
    setRect(0, 0, 50, 50);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start(50);
}

void Enemy::move() {
    setPos(x(), y() + 5);
    if (pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}
