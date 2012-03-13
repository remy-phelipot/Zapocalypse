#include "Controller.h"

Controller::Controller() {
// Init rand
    srand( time( NULL ) );

// Construct the new Controller
    affConsole = NULL;
    myWorld = NULL;
}


void Controller::Start() {
// Create the new window
    affConsole = new Affichage();

// When the new window is created, call the "InitialiseWorld" method
// parameterized with the size of the map.
/** Called right now, because no window **/
    InitialiseWorld( DEFAULT_NB_HEXAGON_X, DEFAULT_NB_HEXAGON_Y );
}


void Controller::InitialiseWorld( int pNbHexagonX, int pNbHexagonY ) {
    myWorld = new World( pNbHexagonX, pNbHexagonY );

// Call the play function
/** No Window **/
    Play();
}


void Controller::Play( ) {
    char pressedKey = 0;
    unsigned int i = 0;
    int valX, valY;

    do {
        myVWorld -> PlayTurn();
    } while ( pressedKey != 'Q' );
}
