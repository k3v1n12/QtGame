#include "playerrect.h"
#include<QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>

PlayerRect::PlayerRect(QGraphicsItem* parent)
    :QGraphicsPixmapItem(parent)
    ,m_playerReady(true)
{
    m_MediaPlayer = new QMediaPlayer();
    m_AudioOutput = new QAudioOutput;
    m_MediaPlayer->setAudioOutput(m_AudioOutput);
    m_MediaPlayer->setSource(QUrl("qrc:/sounds/sounds/bullet.mp3"));
    m_AudioOutput->setVolume(10);
}

void PlayerRect::keyPressEvent(QKeyEvent *keyEvent)
{
    if(m_playerReady) {

        if(keyEvent->key() == Qt::Key_Left) {
            if(x() > 0) {
                setPos(x() - 10, y());
            }
        }
        else if(keyEvent->key() == Qt::Key_Right) {
            if((x() + 100) < 800) {
                setPos(x() + 10, y());
            }
        }
        else if(keyEvent->key() == Qt::Key_Space) {
            Bullet* bullet = new Bullet();
            scene()->addItem(bullet);
            bullet->setPos(x() + 100 / 2 - 10, y() - 15);

            //play bullet sound
            if(m_MediaPlayer->isPlaying()) {
                m_MediaPlayer->setPosition(0);
            }
            if(m_MediaPlayer->playbackState() == QMediaPlayer::StoppedState) {
                m_MediaPlayer->play();
            }
        }
    }
    else {
        m_MediaPlayer->stop();
    }
}

void PlayerRect::stop()
{
    m_playerReady = false;
}
