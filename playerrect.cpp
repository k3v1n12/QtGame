#include "playerrect.h"
#include<QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>

PlayerRect::PlayerRect()
{

}

void PlayerRect::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Left) {
        if(x() > 0) {
            setPos(x() - 10, y());
        }
    }
    else if(keyEvent->key() == Qt::Key_Right) {
        if((x() + rect().width()) < 800) {
            setPos(x() + 10, y());
        }
    }
    else if(keyEvent->key() == Qt::Key_Space) {
        Bullet* bullet = new Bullet();
        scene()->addItem(bullet);
        bullet->setPos(x() + rect().width() / 2 - bullet->rect().width(), y() - bullet->rect().height());
    }
}
