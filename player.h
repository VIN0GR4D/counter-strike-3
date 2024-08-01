#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include "score.h"

class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Player(Score *score);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public slots:
    void shoot();

private:
    Score *score;
};

#endif // PLAYER_H
