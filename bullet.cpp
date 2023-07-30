#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"

Bullet::Bullet()
{
    setRect(0,0, 10, 50);

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    //collision of Enemy
    QList<QGraphicsItem* > collidingItem = collidingItems();
    for(auto& item: collidingItem) {
        if(typeid(*item) == typeid(Enemy)) {
            scene()->removeItem(item);
            delete item;
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //movement of bullet
    setPos(x(), y() - 10);
    if(y() + rect().height() <= 0) {
        scene()->removeItem(this);
        delete this;
    }
}
