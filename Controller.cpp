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
    int valX, valY;

    do {
// Print the Element
        myWindow -> printGrid();
// Browse the Vector as an iterator to print each Element at its new position
        for ( vector<Element*>::iterator it = myWorld -> begin() ; it != myWorld -> end() ; ++it ) {
            valX = (*it) -> getMyPosition().GetposX();
            valY = (*it) -> getMyPosition().GetposY();
            myWindow -> printAtPosition( valX, valY, (*it) -> getImage() );
        }

// Play a turn
        myWorld -> PlayTurn();
        cout << "Press a key to pass a turn (\'Q\' to exit):";
        fflush( stdin );
        pressedKey = getch();
    } while ( pressedKey != 'Q' );
}

int Controller::getGameDate() {
    return this -> myWorld -> getGameDate();
}
