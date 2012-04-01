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
}

<<<<<<< HEAD
void Controller::setPlayTurn(bool _b){
    threadWorld->setPlay(_b);
}

=======
int Controller::getGameDate() {
    return this -> myWorld -> getGameDate();
}

int Controller::getHumanNumber() {
    return this -> myWorld -> getHumanNumber();
}
>>>>>>> bb29588a58a72b3ca3e626871e3be15c95207eea
