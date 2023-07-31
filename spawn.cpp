#include "spawn.h"
#include <QTimer>
#include "enemy.h"

Spawn::Spawn(QObject* parent)
    : QObject(parent)
{
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(spawn()));
    m_timer->start(2000);
    std::random_device rd;
    m_randomEngine.seed(rd());

}

void Spawn::stop()
{
    m_timer->stop();
}

void Spawn::spawn()
{
    Enemy* enemy = new Enemy();
    std::uniform_int_distribution<int> distribution(0, 700);
    int randomNum = distribution(m_randomEngine);
    enemy->setPos(randomNum, 0);
}
