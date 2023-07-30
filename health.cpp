#include "health.h"

#include<QFont>

Health::Health(QGraphicsItem* parent)
    : QGraphicsTextItem(parent)
{
    m_Health = 3;
    setPlainText(QString("Health: ")+ QString::number(m_Health));
    setDefaultTextColor(QColor("red"));
    setFont(QFont("times", 16));
}

void Health::decreaseHealth()
{
    m_Health--;
    setPlainText(QString("Health: ")+ QString::number(m_Health));
}

int Health::getHealth()
{
    return m_Health;
}
