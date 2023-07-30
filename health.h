#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem* parent = 0);
    void decreaseHealth();
    int getHealth();

private:
    int m_Health;
};

#endif // HEALTH_H
