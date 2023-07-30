#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy(QGraphicsScene* mainScene)
{
    setRect(0,0, 100, 100);
    mainScene->addItem(this);
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    //movement of Enemy
    setPos(x(), y() + 10);
    if(y() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}
