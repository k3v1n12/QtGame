#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "playerrect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //Create an item to add to the scene
    PlayerRect* player  = new PlayerRect();

    //configure item
    player->setRect(0, 0, 100, 100);

    //add item to scene
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create a view to visualise the scene
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view->width() / 2 - player->rect().width() / 2, view->height() - player->rect().height());

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show view
    view->show();

    return a.exec();
}
