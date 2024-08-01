// bullet.h
#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "score.h"

class Bullet : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Bullet(Score *score);

public slots:
    void move();
    void checkCollisions();

private:
    Score *score;
};

#endif // BULLET_H
