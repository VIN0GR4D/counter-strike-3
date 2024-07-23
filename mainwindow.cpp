#include "mainwindow.h"
#include <QTimer>
#include "enemy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this)), player(new Player()) {
    setCentralWidget(view);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    scene->addItem(player);
    player->setPos(400, 500);

    // Делаем игрока фокусом для получения событий от клавиатуры и мыши
    player->setFocus();

    // Настраиваем виджет для отслеживания движения мыши
    view->setMouseTracking(true);
    view->viewport()->setMouseTracking(true);

    // Таймер для появления врагов
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        Enemy *enemy = new Enemy();
        scene->addItem(enemy);
    });
    timer->start(2000);
}

MainWindow::~MainWindow() {}
