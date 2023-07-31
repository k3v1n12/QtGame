#ifndef PLAYERRECT_H
#define PLAYERRECT_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class PlayerRect : public QGraphicsPixmapItem
{
public:
    PlayerRect(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent* keyEvent);

    void stop();
private:
    QMediaPlayer* m_MediaPlayer;
    QAudioOutput* m_AudioOutput;
    bool m_playerReady;
};

#endif // PLAYERRECT_H
