#include "score.h"
#include<QFont>

Score::Score(QGraphicsItem* parent)
    : QGraphicsTextItem(parent)
{
    m_Score = 0;
    setPlainText(QString("Score: ")+ QString::number(m_Score));
    setDefaultTextColor(QColor("blue"));
    setFont(QFont("times", 16));
}

void Score::increaseScore()
{
    m_Score++;
    setPlainText(QString("Score: ")+ QString::number(m_Score));
}

int Score::getScore()
{
    return m_Score;
}
