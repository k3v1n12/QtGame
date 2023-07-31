#include "gameover.h"
#include<QFont>

Gameover::Gameover()
{
    setFont(QFont("times", 25));
    setDefaultTextColor(QColor("red"));
    setPlainText(QString("Gameover"));

}
