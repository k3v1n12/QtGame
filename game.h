#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "playerrect.h"
#include "spawn.h"
#include "score.h"
#include "health.h"
#include "gameover.h"

class Game
{
public:
    Game();
    ~Game();

    QGraphicsScene* scene;
    PlayerRect* player;
    QGraphicsView* view;
    Spawn* spawn;
    Score* score;
    Health* health;
    Gameover* gameover;

    void stop();

private:
    QMediaPlayer* m_MediaPlayer;
    QAudioOutput* m_AudioOutput;
};

#endif // GAME_H
