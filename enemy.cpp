#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"

extern Game* game;

Enemy::Enemy()
{
    setRect(0,0, 100, 100);
    game->scene->addItem(this);
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    //movement of Enemy
    setPos(x(), y() + 10);
    if(y() > 600) {
        game->health->decreaseHealth();
        scene()->removeItem(this);
        delete this;
    }
}
