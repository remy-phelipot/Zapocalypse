#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstdlib>
#include <cstdio>

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

        void setPlayTurn(bool);



};

#endif
