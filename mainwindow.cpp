#include "mainwindow.h"
#include "enemy.h"
#include "score.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this)), score(new Score()) {

    // Создаем игрока и передаем указатель на объект Score
    player = new Player(score);

    setCentralWidget(view);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    scene->addItem(player);
    player->setPos(400, 500);

    // Добавляем счет на сцену в правый верхний угол
    score->setPos(700, 0);
    scene->addItem(score);

    // Делаем игрока фокусом для получения событий от клавиатуры и мыши
    player->setFocus();

    // Таймер для появления врагов
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        Enemy *enemy = new Enemy();
        scene->addItem(enemy);
    });
    timer->start(2000);
}

MainWindow::~MainWindow() {}
