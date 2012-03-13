#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstdlib>

#include "Affichage.h"
#include "Element.h"
#include "World.h"
#include "Human.h"
#include "Position.h"

#define TEST_HUMAN_NUMBER 2

class Controller {
    private:
// Pointer to the World
        World *myVWorld;
// Pointer to the window
        Affichage *affConsole;
// Map size, hexagon number
        int sizeX, sizeY;

    public:
// Construct the controller
        Controller();
// Start the controller, initialise the game and window
        void Start( int, int );
// Allow the user to play the game
        void Play();
// Variable used to stop the thread
        bool playNow;
};

#endif
