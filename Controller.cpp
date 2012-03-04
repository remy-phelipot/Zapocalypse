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
    myVElement -> push_back( *humanTest );

    affConsole -> printAtPosition( 29, 19, humanTest -> getImage() );

// Prompt confirmation message
    cout << "End of game initialisation, press key to play..." << endl;
    fflush( stdin );
    getch();

    Play();
}

void Controller::Play() {
    char pressedKey = 0;

    do {
        affConsole -> clearInputZone();
        cout << "Press key to move the character : ";
        fflush( stdin );
        pressedKey = getch();
        fflush( stdin );
        affConsole -> clearInputZone();

        if ( pressedKey != 'Q' ) {
// For each element in the vector, call the method Action
            myVElement -> front().Action();
            getch();
        }
    } while ( pressedKey != 'Q' );
}
