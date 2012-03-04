#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "World.h"
#include "Affichage.h"

class Controller {
    public:
        Controller( Affichage & );
        void start();

    private:
        World *ptrWorld;
        Affichage *affConsole;
};

#endif
