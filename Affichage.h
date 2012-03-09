#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
using namespace std;

#include "econio.h"

class Affichage {
    private:
        int sizeX;
        int sizeY;
        int nbHexagonX;
        int nbHexagonY;

    public:
        Affichage( int, int );

// printGrid : print the grid on the console
        void printGrid();
// hexagonToSize : convert the coordinates from Hexagon to Console screen
        void hexagonToSize( int *, int * );
// printAtPosition : print the letter of an element in the grid
        void printAtPosition( int, int, char );
// Clear the input zone and move the cursor at the end of the grid
        void clearInputZone();

        int getSizeX();
        int getSizeY();
};

#endif
