#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "playerrect.h"
#include "spawn.h"
#include "score.h"
#include "health.h"

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

};

#endif // GAME_H
