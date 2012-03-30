#include "world_map_area.h"
#include <QSizePolicy>
namespace gui{
World_map_area::World_map_area(QWidget * _parent, unsigned int _width, unsigned int _height):
    QGraphicsView(),
    hexagons(),
    scene(),
    hexagon("hexa"),
    zombie("zombie.png"),
    humanF("Woman.png"),
    humanM("Man.png"),
    rabbit("Rabbit.png"),
    town("City.png"),
    tree("Tree.png")
{
    //Resize pictures
    /*hexagon = hexagon.scaled(QSize(zombie.width()/6.0,zombie.height()/6.0),
                             Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);48*/
    hexagon = hexagon.scaledToWidth(48,Qt::SmoothTransformation);

    zombie = zombie.scaled(QSize(zombie.width()/6.0,zombie.height()/6.0),
                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);

    humanF = humanF.scaled(QSize(humanF.width()/6.0,humanF.height()/6.0),
                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);


    humanM = humanM.scaled(QSize(humanM.width()/6.0,humanM.height()/6.0),
                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);

    rabbit = rabbit.scaled(QSize(rabbit.width()/6.0,rabbit.height()/6.0),
                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);

    town = town.scaled(QSize(town.width()/6.0,town.height()/6.0),
                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);

    tree = tree.scaled(QSize(tree.width()/6.0,tree.height()/6.0),
                           Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);




    setParent(_parent);
    setScene(&scene);

    //nbHexa
    unsigned int nbHexaX = 20;
    unsigned int nbHexaY = 20;

    //set graphic view and scene size
    scene.setSceneRect(0,0,_width, _height);
    setFixedSize(_width,_height);

    //set scrollbars policies
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //calculating some useful values (for performance issues)
    gapInterHexagon = xGap(hexagon.width());
    gapBHexagon = gapInterHexagon + hexagon.width();
    unevenLineGap = gapInterHexagon + (hexagon.width()/2.0)*std::cos(MY_PI/3.0);
    imageHeightDivBy2 = hexagon.height()/2.0;

    //calculating total size of grid
    gTotalSizeX = nbHexaX/2.0 * (hexagon.width() + gapInterHexagon);
    gTotalSizeY = nbHexaY/2.0 * (hexagon.height())+imageHeightDivBy2;
    wingapX = (_width - gTotalSizeX) /2.0;
    wingapY = (_height - gTotalSizeY) /2.0;


    for (unsigned int i = 0; i < 200 ; i ++){
        QGraphicsPixmapItem * it = new QGraphicsPixmapItem(hexagon);
        it->setZValue(1);
        hexagons.push_back(it);
    }
    unsigned int z = 0;
    for (unsigned int j = 0; j < 20 ; j ++){
        for (unsigned int i = 0; i < 10 ; i ++){
            if (j % 2 == 0){
                hexagons[z]->setPos(((double)i * gapBHexagon) + wingapX,(double)j* imageHeightDivBy2 + wingapY);
            }else{
                hexagons[z]->setPos((((double)i * gapBHexagon) + unevenLineGap)+ wingapX,(double)j* imageHeightDivBy2 + wingapY);
            }
            scene.addItem(hexagons[z]);
            z++;
        }
    }


}

World_map_area::~World_map_area(){
    //Remove hexagons
    for (unsigned int i = 0; i < hexagons.size();i++){
        scene.removeItem(hexagons[i]);
        delete(hexagons[i]);
    }

    //Remove items
    for (std::vector<struct ItemPosition>::iterator it = items.begin(); it!=items.end(); it++) {
        scene.removeItem(it->item);
        delete(it->item);
    }
}

bool World_map_area::removeItem(unsigned int _x, unsigned int _y){

    for (std::vector<struct ItemPosition>::iterator it = items.begin(); it!=items.end(); ++it) {
        if (it->x == _x && it->y == _y){
            scene.removeItem(it->item);
            delete(it->item);
            items.erase(it);
            return true;
        }
    }
    return false;
}

bool World_map_area::clearAll(){

    for (std::vector<struct ItemPosition>::iterator it = items.begin(); it!=items.end(); ++it) {
            delete(it->item);
    }
    items.clear();
    return true;

}


void World_map_area::addItem(unsigned int _x, unsigned int _y, ItemType _itType){
    struct ItemPosition ip;
    ip.x = _x;
    ip.y = _y;
    ip.item = createQGraphicsPixmapItem (_itType);

    ip.item->setZValue(2);


    if (_y % 2 == 0){
        ip.item->setPos(((_x/2) * gapBHexagon) + wingapX,_y * imageHeightDivBy2 + wingapY);
    }else{//uneven line
        ip.item->setPos(((_x/2) * gapBHexagon) + unevenLineGap+ wingapX,_y * imageHeightDivBy2 + wingapY);
    }

    scene.addItem(ip.item);

    items.push_back(ip);//Save item adress
}

double World_map_area::xGap (double _width) const{
    return _width*(1 - std::cos(MY_PI/3.0));
}

QGraphicsPixmapItem * World_map_area::createQGraphicsPixmapItem (ItemType _itType){
    QGraphicsPixmapItem * it = NULL;
    switch(_itType){
    case zombieType :
        it = new QGraphicsPixmapItem(zombie);
        break;
    case humanMType :
        it = new QGraphicsPixmapItem(humanM);
        break;
    case humanWType:
        it = new QGraphicsPixmapItem(humanF);
        break;
    case townType :
        it = new QGraphicsPixmapItem(town);
        break;
    case rabbitType:
        it = new QGraphicsPixmapItem(rabbit);
        break;
    case hexagonType:
        it = new QGraphicsPixmapItem(hexagon);
    }
    return it;
}

}
