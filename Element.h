#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
using namespace std;

#include "Position.h"

class Element {
    public:
        Element();
        Element( int, int );
        virtual bool Action();
        Position getMyPosition();
        void setMyPosition( int, int );
        void setImage( char );
        char getImage();

    private:
        Position myPosition;
        char image;
};

#endif // ELEMENTS_H
