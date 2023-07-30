#ifndef PLAYERRECT_H
#define PLAYERRECT_H

#include <QGraphicsRectItem>

class PlayerRect : public QGraphicsRectItem
{
public:
    PlayerRect();
    void keyPressEvent(QKeyEvent* keyEvent);
};

#endif // PLAYERRECT_H
