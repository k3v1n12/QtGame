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
        setPos(x() - 10, y());
    }
    else if(keyEvent->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    }
    else if(keyEvent->key() == Qt::Key_Space) {
        Bullet* bullet = new Bullet();
        this->scene()->addItem(bullet);
        bullet->setPos(x() + this->rect().width() / 2 - bullet->rect().width(), y() - bullet->rect().height());
    }
}
