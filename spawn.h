#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <random>
#include <QGraphicsScene>

class Spawn : public QObject
{
    Q_OBJECT
public:
    explicit Spawn(QGraphicsScene* mainScene);

public slots:
    void spawn();

private:
    std::mt19937 m_randomEngine;
    QGraphicsScene* m_mainScene;

};

#endif // SPAWN_H
