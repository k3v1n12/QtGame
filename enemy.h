#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsScene* mainScene);

public slots:
    void move();

};

#endif // ENEMY_H
