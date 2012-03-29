#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
using namespace std;

#include "econio.h"

// Size of the World
#define DEFAULT_NB_HEXAGON_X 20
#define DEFAULT_NB_HEXAGON_Y 20

class Affichage {
    private:
        int sizeX;
        int sizeY;
        int nbHexagonX;
        int nbHexagonY;

    public:
        Affichage();
        Affichage( int, int );

// printGrid : print the grid on the console
        void printGrid();
// hexagonToSize : convert the coordinates from Hexagon to Console screen
        void hexagonToSize( int *, int * );
// printAtPosition : print the letter of an element in the grid
        void printAtPosition( int, int, char );
};

#endif
