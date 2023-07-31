#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "playerrect.h"
#include "spawn.h"

Game::Game()
{
    //Create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    //create a view to visualise the scene
    view = new QGraphicsView(scene);
    view->setBackgroundBrush(QBrush(QImage(":/images/images/background.jpg")));
    view->setFixedSize(800, 600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Create a player to add to the scene
    player = new PlayerRect();

    //draw player
    QPixmap playerImage = QPixmap(":/images/images/player.png").scaled(QSize(100, 100));
    player->setPixmap(playerImage);

    player->setPos(view->width() / 2 - 50, view->height() - 100);
    //add player to scene
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //spawn Enemy
    spawn = new Spawn();

    //Add Score to view
    score = new Score();
    scene->addItem(score);

    //Add Score to view
    health = new Health();
    health->setPos(0, 25);
    scene->addItem(health);

    //play background music
    m_MediaPlayer = new QMediaPlayer();
    m_AudioOutput = new QAudioOutput;
    m_MediaPlayer->setAudioOutput(m_AudioOutput);
    m_MediaPlayer->setSource(QUrl("qrc:/sounds/sounds/background.mp3"));
    m_AudioOutput->setVolume(10);
    m_MediaPlayer->play();
    //show view
    view->show();
}

Game::~Game()
{
    delete scene;
    delete player;
    delete view;
    delete spawn;
    delete score;
    delete health;
}

void Game::stop()
{

    QList<QGraphicsItem *> items = scene->items();

    spawn->stop();
    m_MediaPlayer->stop();

    foreach( QGraphicsItem *item, items ) {

        if(auto bulletItem{dynamic_cast<Bullet*>(item)}) {
            bulletItem->stop();
        }
        else if(auto enemyItem{dynamic_cast<Enemy*>(item)}) {
            enemyItem->stop();
        }
        else if(auto playerItem{dynamic_cast<PlayerRect*>(item)}) {
            playerItem->stop();
        }
    }

    gameover = new Gameover();
    gameover->setPos(350, 250);
    scene->addItem(gameover);
}
