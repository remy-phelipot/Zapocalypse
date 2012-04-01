#ifndef WORLD_MAP_AREA_H
#define WORLD_MAP_AREA_H

#include <QGraphicsView>
#include <vector>
#include <QGraphicsPixmapItem>
#include <cmath>
#include <iostream>
#include "Element.h"

namespace gui{

//Pi constant, for cross platform issues
#define MY_PI 3.1415926535897932384626433832795029L

//Structure to store position of an item
struct ItemPosition{
    QGraphicsPixmapItem * item;
    unsigned int x;
    unsigned int y;
};

/*//Enumeration of all items
enum ItemType{
    hexagonType,
    zombieType,
    humanMType,
    humanWType,
    townType,
    rabbitType
};*/

class World_map_area : public QGraphicsView
{
public:
    World_map_area(QWidget *, unsigned int _width, unsigned int _height);
    //Add item in map
    void addItem(unsigned int, unsigned int,ItemType);
    bool removeItem(unsigned int, unsigned int);
    bool clearAll();
    ~World_map_area();
private:
    std::vector <QGraphicsPixmapItem *> hexagons;
    std::vector <struct ItemPosition> items;

    QGraphicsScene scene;
    QPixmap hexagon;
    QPixmap zombie;
    QPixmap humanF;
    QPixmap humanM;
    QPixmap town;
    QPixmap rabbit;
    QPixmap tree;

    double gapInterHexagon;
    double gapBHexagon;
    double unevenLineGap;
    double imageHeightDivBy2;

    double gTotalSizeX;
    double gTotalSizeY;
    double wingapX;
    double wingapY;

    /* Return gap between 2 hexagons */
    double xGap (double _width) const;
    QGraphicsPixmapItem * createQGraphicsPixmapItem (ItemType);

};

}
#endif // WORLD_MAP_AREA_H
