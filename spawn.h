#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <random>
#include <QGraphicsScene>

class Spawn : public QObject
{
    Q_OBJECT
public:
    explicit Spawn();

public slots:
    void spawn();

private:
    std::mt19937 m_randomEngine;

};

#endif // SPAWN_H
