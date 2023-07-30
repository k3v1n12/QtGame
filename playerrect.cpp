#include "playerrect.h"
#include<QKeyEvent>

PlayerRect::PlayerRect()
{

}

void PlayerRect::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    }
    else if(keyEvent->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    }
    else if(keyEvent->key() == Qt::Key_Up) {
        setPos(x(), y() - 10);
    }
    else if(keyEvent->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    }
}
