#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"

extern Game* game;

Enemy::Enemy(QGraphicsPixmapItem* parent)
    : QObject()
    ,QGraphicsPixmapItem(parent)
{
    //Draw Enemy
    QPixmap enemyImage = QPixmap(":/images/images/enemy.png").scaled(QSize(100, 100));
    setPixmap(enemyImage);
    game->scene->addItem(this);
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(50);
}

void Enemy::move()
{
    //collision with Player
    QList<QGraphicsItem* > collidingItem = collidingItems();
    for(auto& item: collidingItem) {
        if(typeid(*item) == typeid(PlayerRect)) {

            //decrease player health
            game->health->decreaseHealth();

            if(game->health->getHealth() <= 0) {
                game->stop();
            }

            //delete enemy
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    //movement of Enemy
    setPos(x(), y() + 10);
    if(y() > 600) {
        game->health->decreaseHealth();

        if(game->health->getHealth() <= 0) {
            game->stop();
        }

        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::stop()
{
    m_timer->stop();
}
