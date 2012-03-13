#include "World.h"

World::World() {}

Position World::newCoordinates( int pNbHexagonX, int pNbHexagonY ) {
// Variables
    int valX;
    int valY;
    bool valide = false;

    while ( valide == false ) {
        valX = (rand() % ( pNbHexagonX - 0 ) + 1);
        valY = (rand() % ( pNbHexagonY - 0 ) + 1);

        if ( valX % 2 == 0 && valY % 2 == 1 ) {
            valY++;
        }

        if ( valX % 2 == 1 && valY % 2 == 0 ) {
            valY--;
        }
// Check if the coordinates arren't already used
        valide = true;
    }

    Position newPosition( valX, valY );
// Add the new Position into the map
    //mapWorld[newPosition] = 1;

// Return the new Position
    return newPosition;
}
