#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent), score(0) {
    // Изначально счет равен 0
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black); // Цвет текста
    setFont(QFont("times", 16));    // Шрифт и размер
}

void Score::increase() {
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() const {
    return score;
}
