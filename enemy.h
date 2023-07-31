#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsPixmapItem* parent = nullptr);

public slots:
    void move();

    void stop();

private:
    QTimer* m_timer;

};

#endif // ENEMY_H
