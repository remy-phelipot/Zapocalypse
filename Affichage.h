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
};

#endif
