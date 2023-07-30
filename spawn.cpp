#include "spawn.h"
#include <QTimer>
#include "enemy.h"

Spawn::Spawn()
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(2000);
    std::random_device rd;
    m_randomEngine.seed(rd());

}

void Spawn::spawn()
{
    Enemy* enemy = new Enemy();
    std::uniform_int_distribution<int> distribution(0, 700);
    int randomNum = distribution(m_randomEngine);
    enemy->setPos(randomNum, 0);
}
