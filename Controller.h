#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Affichage.h"
#include "Element.h"
#include "World.h"
#include "Human.h"

#define TEST_HUMAN_NUMBER 2

class Controller {
    public:
// Construct the controller
        Controller( Affichage & );
// Start the controller, initialise the game
        void Start();
// Allow the user to play the game
        void Play();
// Variable used to stop the thread
        bool playNow;

    private:
        World *myVWorld;
        Affichage *affConsole;
};

#endif
