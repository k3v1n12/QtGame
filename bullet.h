#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsPixmapItem* parent = nullptr);

public slots:
    void move();

    void stop();

private:
    QTimer* m_timer;

};

#endif // BULLET_H
