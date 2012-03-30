#include "World.h"
#include "Zombie.h"

World::World( int pNbHexagonX, int pNbHexagonY ) {
    nbHexagonX = pNbHexagonX;
    nbHexagonY = pNbHexagonY;

// Variables
    Position tmpPosition;

// Initialise default settings
    GameDate = 0;

// Initialise default population
    for ( int i = 0 ; i <= TEST_HUMAN_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initialHuman = new Human( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initialHuman );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

// Initialise default animal number
    for ( int i = 0 ; i <= TEST_ANIMAL_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initAnimal = new Animal( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initAnimal );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

// Initialise default zombie population
    for ( int i = 0 ; i <= TEST_ZOMBIE_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initZombie = new Zombie( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initZombie );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

    cout << "World initialized.";
    fflush( stdin );
    //getch();
}


Position World::newCoordinates() {
// Variables
    int valX;
    int valY;
    bool valide = false;
    Position newPosition( 0, 0 );

    while ( valide == false ) {
// rand()%(b-a)+a
        valX = rand() % nbHexagonX;
        valY = rand() % nbHexagonY;

        if ( valX % 2 == 0 && valY % 2 == 1 ) {
            valY++;
        }

        if ( valX % 2 == 1 && valY % 2 == 0 ) {
            valY--;
        }

        newPosition = Position( valX, valY );

// Check if the coordinates aren't already used in the map
        if ( mapWorld.find( newPosition ) == mapWorld.end() && valX < 20 && valX >= 0 && valY < 20 && valY >= 0 ) {
            valide = true;
        }
    }
    cout << "New coordinates : x=" << valX  << " y=" << valY << endl;
// Return the new Position
    return newPosition;
}


void World::PlayTurn () {
// For each element in the vector, call the Action method
    for ( unsigned int i = 0 ; i <= ( size() - 1 ) ; i++ ) {
        at( i ) -> Action();
    }
    GameDate++;
}

map <Position, unsigned> *World::getMapWorld() {
    return &mapWorld;
}
