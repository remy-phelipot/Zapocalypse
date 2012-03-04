#include "Controller.h"

Controller::Controller( Affichage::Affichage &pAffConsole ) {
    affConsole = &pAffConsole;
    ptrWorld = new World();
}

void Controller::start() {
    affConsole -> printGrid();
}
