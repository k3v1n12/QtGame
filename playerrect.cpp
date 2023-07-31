#include "playerrect.h"
#include<QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>

PlayerRect::PlayerRect()
{
    m_MediaPlayer = new QMediaPlayer();
    m_AudioOutput = new QAudioOutput;
    m_MediaPlayer->setAudioOutput(m_AudioOutput);
    m_MediaPlayer->setSource(QUrl::fromLocalFile("D:\\qtproject\\QtGame\\sounds\\bullet.mp3"));
    m_AudioOutput->setVolume(10);
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

        //play bullet sound
        if(m_MediaPlayer->isPlaying()) {
            m_MediaPlayer->setPosition(0);
        }
        if(m_MediaPlayer->playbackState() == QMediaPlayer::StoppedState) {
            m_MediaPlayer->play();
        }
    }
}
