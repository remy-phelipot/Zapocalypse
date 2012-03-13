#include "Controller.h"

Controller::Controller() {
// Init rand
    srand( time( NULL ) );

// Construct the new Controller
    myWindow = NULL;
    myWorld = NULL;
}


void Controller::Start() {
// Create the new window
    myWindow = new Affichage();

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
    char pressedKey;
    unsigned int i = 0;
    int valX, valY;

    do {
// Print the Element
        myWindow -> printGrid();
// Browse the Vector to print each Element at its new position
        for ( i = 0 ; i <= ( myWorld -> size() - 1 ) ; i++ ) {
            valX = myWorld -> at( i ) -> getMyPosition().GetposX();
            valY = myWorld -> at( i ) -> getMyPosition().GetposY();
            myWindow -> printAtPosition( valX, valY, myWorld -> at( i ) -> getImage() );
        }
// Play a turn
        myWorld -> PlayTurn();
        cout << "Press a key to pass a turn (\'Q\' to exit):";
        fflush( stdin );
        pressedKey = getch();
    } while ( pressedKey != 'Q' );
}
