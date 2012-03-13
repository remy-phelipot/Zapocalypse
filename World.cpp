#include "World.h"

World::World( int pNbHexagonX, int pNbHexagonY ) {
    nbHexagonX = pNbHexagonX;
    nbHexagonY = pNbHexagonY;

// Variables
    Position tmpPosition;

// Initialise default population
    for ( int i = 0 ; i <= TEST_HUMAN_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initialHuman = new Human( tmpPosition.GetposX(), tmpPosition.GetposY() );
        push_back( initialHuman );
    }
}


Position World::newCoordinates() {
// Variables
    int valX;
    int valY;
    bool valide = false;

    while ( valide == false ) {
// rand()%(b-a)+a
        valX = rand() % ( (nbHexagonX-1) - 0 ) + 0;
        valY = rand() % ( (nbHexagonY-1) - 0 ) + 0;

        if ( valX % 2 == 0 && valY % 2 == 1 ) {
            valY++;
        }

        if ( valX % 2 == 1 && valY % 2 == 0 ) {
            valY--;
        }
// Check if the coordinates aren't already used in the map
        valide = true;
    }

    Position newPosition( valX, valY );
// Add the new Position into the map
    //mapWorld[newPosition] = 1;

// Return the new Position
    return newPosition;
}


void World::PlayTurn () {
// For each element in the vector, call the Action method
    for ( unsigned int i = 0 ; i <= ( size() - 1 ) ; i++ ) {
        at( i ) -> Action();
    }
}
