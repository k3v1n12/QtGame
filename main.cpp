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

    //show view
    view->show();

    return a.exec();
}
