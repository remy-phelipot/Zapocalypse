#include "Controller.h"

Controller::Controller() {
// Init rand
    srand( time( NULL ) );

// Construct the new Controller
    myWindow = new gui::Main_Window(this);
    myWorld = NULL;

    InitialiseWorld( 20, 20);
    myWindow->show();
}


void Controller::Start() {
// Create the new window


// When the new window is created, call the "InitialiseWorld" method
// parameterized with the size of the map.
/** Called right now, because no window **/
    //InitialiseWorld( 20, 20 );
}


void Controller::InitialiseWorld( int pNbHexagonX, int pNbHexagonY ) {
    myWorld = new World( pNbHexagonX, pNbHexagonY );

    threadWorld = new Thread_World(this,myWorld,myWindow);


// Call the play function
/** No Window **/
   // Play();
}


void Controller::Play( ) {
    threadWorld->start();
/*
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
*/
}

void Controller::setPlayTurn(bool _b){
    threadWorld->setPlay(_b);
}

