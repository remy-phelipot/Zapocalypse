#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

#include "Position.h"
#include "Element.h"

class World : public vector <Element*> {
    public:
        World();
        Position newCoordinates( int, int );

    private:
        map <Position, unsigned> mapWorld;
};

#endif // WORLD_H
