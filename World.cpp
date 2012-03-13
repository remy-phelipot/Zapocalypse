#include "World.h"

World::World() {
    unsigned int i;
    int valX, valY;
    Position tmpPosition;

// Initialise default population
    for ( int i = 0 ; i <= TEST_HUMAN_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = myVWorld -> newCoordinates( nbHexagonX, nbHexagonY );
        Element *humanTest = new Human( tmpPosition.GetposX(), tmpPosition.GetposY() );
        myVWorld -> push_back( humanTest );
    }

// Browse the Vector to print each element at its new position
    for ( i = 0 ; i <= ( myVWorld -> size() - 1 ) ; i++ ) {
        valX = myVWorld -> at( i ) -> getMyPosition().GetposX();
        valY = myVWorld -> at( i ) -> getMyPosition().GetposY();
        affConsole -> printAtPosition( valX, valY, myVWorld -> at( i ) -> getImage() );
    }

// Prompt confirmation message
    cout << "End of game initialisation, press key to play..." << endl;
    fflush( stdin );
    getch();
}


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

void World::PlayTurn () {
    do {
        affConsole -> clearInputZone();
        cout << "Press a key to pass a turn (\'Q\' to exit)";
        fflush( stdin );
        pressedKey = getch();
        fflush( stdin );
        affConsole -> clearInputZone();

        if ( pressedKey != 'Q' ) {
// For each element in the vector, call the Action method
            for ( i = 0 ; i <= ( myVWorld -> size() - 1 ) ; i++ ) {
                myVWorld -> at( i ) -> Action();
                cout << "Press a key to go to the next element" << endl;
                getch();
            }
// Clear the screen
            clrscr();
// Print the grid
            affConsole -> printGrid();
// Browse the Vector to print each element at its new position
            for ( i = 0 ; i <= ( myVWorld -> size() - 1 ) ; i++ ) {
                valX = myVWorld -> at( i ) -> getMyPosition().GetposX();
                valY = myVWorld -> at( i ) -> getMyPosition().GetposY();
                affConsole -> printAtPosition( valX, valY, myVWorld -> at( i ) -> getImage() );
            }
        }
    } while ( pressedKey != 'Q' );
}
