#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstdlib>
#include <cstdio>

#include "Affichage.h"
#include "World.h"

class Controller {
    private:
// Pointer to my World
        World *myWorld;
// Pointer to my window
        Affichage *myWindow;
// Map size, number of hexagon
        int nbHexagonX, nbHexagonY;

    public:
// Construct the controller
        Controller();
// Start the controller, initialise the window
        void Start();
// Initialise the World
        void InitialiseWorld( int, int );
// Play the game until stopped
        void Play();
// Variable used to stop the thread/play turn loop
        bool playGame;
};

#endif
