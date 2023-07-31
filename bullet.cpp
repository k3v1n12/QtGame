#include "bullet.h"
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game* game;

Bullet::Bullet(QGraphicsPixmapItem* parent)
    : QObject()
    ,QGraphicsPixmapItem(parent)
{
    //draw bullet
    QPixmap bulletImage = QPixmap(":/images/images/bullet.png").scaled(QSize(20, 20));
    setPixmap(bulletImage);

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(50);
}

void Bullet::move()
{
    //collision with Enemy
    QList<QGraphicsItem* > collidingItem = collidingItems();
    for(auto& item: collidingItem) {
        if(typeid(*item) == typeid(Enemy)) {

            //increase player score
            game->score->increaseScore();

            //delete enemy
            scene()->removeItem(item);
            delete item;

            //delete bullet
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //movement of bullet
    setPos(x(), y() - 10);
    if(y() + 20 <= 0) {
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::stop()
{
    m_timer->stop();
}
