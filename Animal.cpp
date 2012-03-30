#include "Animal.h"

Animal::Animal() {
    cout << "Animal : default constructor." << endl;
    initAnimal();
}

Animal::Animal( int pPosX, int pPosY, World *pMyWorld ) :
Element::Element( pPosX, pPosY ),
Mobile( pPosX, pPosY, pMyWorld ),
Resource() {
    cout << "Animal : parameterized constructor." << endl;
    initAnimal();
}

// initResource called by the constructor
void Animal::initAnimal () {
// Read a new name in the name file
    name = "BasicRabbit";
    SetmoveRange( 1 );
    SetvisionRange( 1 );

// Image of an Animal : A
    Resource::setImage( ANIMAL_IMAGE );
// Set Type of Element
    Resource::setType( rabbitType );
}

bool Animal::Action() {
    cout << "Animal basic action, moving..." << endl;
    MoveObject();
// No problem
    return true;
// If there is a problem, return false and delete the element (fail)
}
