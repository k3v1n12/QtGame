#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    this->setRect(0,0, 10, 50);

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    this->setPos(x(), y() - 10);
    if(y() + this->rect().height() <= 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
