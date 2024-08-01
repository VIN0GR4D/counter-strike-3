#include "player.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

Player::Player(Score *score) : score(score) {
    setRect(0, 0, 50, 50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}

void Player::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // Перемещаем игрока в позицию курсора по горизонтали
    QPointF pos = event->scenePos();
    setPos(pos.x() - rect().width() / 2, y());
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        shoot(); // Создает пулю и добавляет ее на сцену
    }
}

void Player::shoot() {
    Bullet *bullet = new Bullet(score);
    bullet->setPos(x() + rect().width() / 2 - bullet->rect().width() / 2, y() - bullet->rect().height());
    scene()->addItem(bullet);
}
