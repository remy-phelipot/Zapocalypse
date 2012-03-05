#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Affichage.h"
#include "Element.h"
#include "World.h"
#include "Human.h"

class Controller {
    public:
// Construct the controller
        Controller( Affichage & );
// Start the controller, initialise the game
        void Start();
// Allow the user to play the game
        void Play();

    private:
        World *myWorld;
        Affichage *affConsole;
        vector <Element*> *myVElement;
};

#endif
