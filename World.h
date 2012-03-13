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

// Number of humans to test the game
#define TEST_HUMAN_NUMBER 5

class World : public vector <Element*> {
    public:
        World();
        Position newCoordinates( int, int );

    private:
        map <Position, unsigned> mapWorld;
// Size of the map
        int nbHexagonX;
        int nbHexagonY;
};

#endif // WORLD_H
