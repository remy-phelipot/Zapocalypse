#include "Town.h"

Town::Town() {
    initTown();
}

Town::Town( int pPosX, int pPosY, World *pMyWorld ) :
Element( pPosX, pPosY ),
Resource( TOWN_DEFAULT_FOOD, TOWN_DEFAULT_WOOD, pPosX, pPosY ) {
    cout << "Town : parameterized constructor." << endl;
    initTown();
}

bool Town::Action() {
    cout << "Town basic action..." << endl;
    return true;
}

void Town::initTown() {
    name = "BasicTown";
// Set image and type
    setImage( TOWN_IMAGE );
    setType( townType );
}
