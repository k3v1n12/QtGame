#include "game.h"
#include <QMediaPlayer>
#include <QAudioOutput>

Game::Game()
{
    //Create a scene
    scene = new QGraphicsScene();

    //Create a player to add to the scene
    player = new PlayerRect();

    //configure item
    player->setRect(0, 0, 100, 100);

    //add player to scene
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create a view to visualise the scene
    view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view->width() / 2 - player->rect().width() / 2, view->height() - player->rect().height());

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
    QMediaPlayer* mediaPlayer = new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setSource(QUrl::fromLocalFile("D:\\qtproject\\QtGame\\sounds\\background.mp3"));
    audioOutput->setVolume(10);
    mediaPlayer->play();
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
