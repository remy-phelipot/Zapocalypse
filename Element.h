#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
using namespace std;

#include "Position.h"

enum ItemType {
    hexagonType,
    zombieType,
    humanMType,
    humanWType,
    townType,
    rabbitType
};

class Element {
    public:
        Element();
        Element( int, int );
        virtual bool Action();
        Position getMyPosition();
        void setMyPosition( int, int );
        void setImage( char );
        char getImage();
        void setType ( ItemType );
        ItemType getType ();

    private:
        Position myPosition;
        char image;
        ItemType type;
};

#endif // ELEMENTS_H
