#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //Create an item to add to the scene
    QGraphicsRectItem* rectItem  = new QGraphicsRectItem();

    //configure item
    rectItem->setRect(0, 0, 100, 100);

    //add item to scene
    scene->addItem(rectItem);

    //create a view to visualise the scene
    QGraphicsView* view = new QGraphicsView(scene);

    //show view
    view->show();

    return a.exec();
}
