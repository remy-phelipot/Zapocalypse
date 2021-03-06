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

#include "Tree.h"


// Number of humans to test the game
#define TEST_ANIMAL_NUMBER 5
#define TEST_HUMAN_NUMBER 5
#define TEST_TOWN_NUMBER 3
#define TEST_TREE_NUMBER 3
#define TEST_ZOMBIE_NUMBER 2

#define TEST_FOOD_QUANTITY 1000
#define TEST_WOOD_QUANTITY 200
#define TEST_FOOD_THRESHOLD 300
#define TEST_WOOD_THRESHOLD 300

#define TEST_TOWN_FREQ 3
#define TEST_TREE_FREQ 7
#define TEST_RABBIT_FREQ 3

class Zombie;

class World : public vector <Element*> {
    public:
        World( int, int );
        Position newCoordinates();
        void PlayTurn();
        map <Position, unsigned> *getMapWorld();
//Resources gestion
        void eatFood( int );
        void useWood( int );
        int getFood();
        int getWood();
        int getFoodThreshold();
        int getWoodThreshold();
        void addFood( int );
        void addWood( int );
// Delete an element
        void deleteElement( int );
// Game informations
// Date
        int getGameDate();
// Human Number
        int getHumanNumber();

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
// Number of humans
        int humanNumber;
};

#endif // WORLD_H
