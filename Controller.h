#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstdlib>
#include <cstdio>
#include <vector>

#include "Element.h"

#include "World.h"
#include "main_window.h"
#include "thread_world.h"
class Controller {
    private:
// Pointer to my World
        World *myWorld;
// Pointer to my window
        gui::Main_Window *myWindow;
// Map size, number of hexagon
        int nbHexagonX, nbHexagonY;

        Thread_World * threadWorld ;
    public:
// Construct the controller
        Controller();
// Start the controller, initialise the window
        void Start();
// Initialise the World
        void InitialiseWorld( int, int );
// Play the game until stopped
        void Play();
<<<<<<< HEAD

        void setPlayTurn(bool);
=======
// Variable used to stop the thread/play turn loop
        bool playGame;
// Return the GameDate in the World
        int getGameDate();
// Return the number of human into the world
        int getHumanNumber();
>>>>>>> bb29588a58a72b3ca3e626871e3be15c95207eea
};

#endif
