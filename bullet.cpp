#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QList>

Bullet::Bullet(Score *score) : score(score) {
    setRect(0, 0, 5, 10);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);
}

void Bullet::move() {
    setPos(x(), y() - 10);
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
        return;
    }
    checkCollisions();
}

void Bullet::checkCollisions() {
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Enemy *>(item)) {
            scene()->removeItem(item);
            scene()->removeItem(this);

            // Увеличиваем счет
            score->increase();

            delete item;
            delete this;
            return;
        }
    }
}
