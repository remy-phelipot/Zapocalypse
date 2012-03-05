#include <stdio.h>

#include "Controller.h"

Controller::Controller( Affichage::Affichage &pAffConsole ) {
    affConsole = &pAffConsole;
    myWorld = new World();
    myVElement = myWorld -> getVectorElement();
}

void Controller::Start() {
    affConsole -> printGrid();

    Element *humanTest = new Human( 10, 10 );
    myVElement -> push_back( humanTest );

    affConsole -> printAtPosition( humanTest -> getMyPosition().GetposX(), humanTest -> getMyPosition().GetposY(), humanTest -> getImage() );

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
            for ( i = 0 ; i <= ( myVElement -> size() - 1 ) ; i++ ) {
                myVElement -> at( i ) -> Action();
                cout << "Press a key to go to the next element" << endl;
                getch();
            }
// Clear the screen
            clrscr();
// Print the grid
            affConsole -> printGrid();
// Browse the Vector to print each element at its new position
            for ( i = 0 ; i <= ( myVElement -> size() - 1 ) ; i++ ) {
                valX = myVElement -> at( i ) -> getMyPosition().GetposX();
                valY = myVElement -> at( i ) -> getMyPosition().GetposY();
                affConsole -> printAtPosition( valX, valY, myVElement -> at( i ) -> getImage() );
            }
        }
    } while ( pressedKey != 'Q' );
}
