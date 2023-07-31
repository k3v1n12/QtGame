#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <random>
#include <QGraphicsScene>
#include <QTimer>

class Spawn : public QObject
{
    Q_OBJECT
public:
    Spawn(QObject* parent = nullptr);

    void stop();

public slots:
    void spawn();

private:
    std::mt19937 m_randomEngine;
    QTimer* m_timer;

};

#endif // SPAWN_H
