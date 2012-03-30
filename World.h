#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std;

#include "Animal.h"
#include "Element.h"
#include "Human.h"
#include "Position.h"
#include "Town.h"
#include "econio.h"

// Number of humans to test the game
#define TEST_HUMAN_NUMBER 5
#define TEST_ANIMAL_NUMBER 5
#define TEST_ZOMBIE_NUMBER 2
#define TEST_TOWN_NUMBER 3

class Zombie;

class World : public vector <Element*> {
    public:
        World( int, int );
        Position newCoordinates();
        void PlayTurn();
        map <Position, unsigned> *getMapWorld();

    private:
        map <Position, unsigned> mapWorld;
// Size of the map
        int nbHexagonX;
        int nbHexagonY;

// Reserves
        int foodQuantity;
        int woodQuantity;
// Threshold Alert
        int foodThresholdAlert;
        int woodThresholdAlert;
// Game date, 1 unity is 1 year
        int GameDate;
};

#endif // WORLD_H
