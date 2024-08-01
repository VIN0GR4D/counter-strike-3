#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem *parent = nullptr);

    void increase();
    int getScore() const;

private:
    int score;
};

#endif // SCORE_H
