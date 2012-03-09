#include <stdio.h>

#include "Controller.h"

Controller::Controller( Affichage::Affichage &pAffConsole ) {
    affConsole = &pAffConsole;
    myVWorld = new World();
}

void Controller::Start() {
    affConsole -> printGrid();

// Initialise default population
    for ( int i = 0 ; i <= TEST_HUMAN_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        Element *humanTest = new Human( 0, 0 );
        myVWorld -> push_back( humanTest );
    }

// Prompt confirmation message
    cout << "End of game initialisation, press key to play..." << endl;
    fflush( stdin );
    getch();

    Play();
}

void Controller::Play() {
    char pressedKey = 0;
    unsigned int i = 0;
    int valX, valY;

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
