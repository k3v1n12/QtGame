#ifndef PLAYERRECT_H
#define PLAYERRECT_H

#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class PlayerRect : public QGraphicsRectItem
{
public:
    PlayerRect();
    void keyPressEvent(QKeyEvent* keyEvent);

private:
    QMediaPlayer* m_MediaPlayer;
    QAudioOutput* m_AudioOutput;
};

#endif // PLAYERRECT_H
