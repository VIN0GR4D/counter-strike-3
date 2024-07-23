#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Player();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public slots:
    void shoot();
};

#endif // PLAYER_H
