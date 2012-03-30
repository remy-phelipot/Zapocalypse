#include "Animal.h"

Animal::Animal() {
    initAnimal();
}

Animal::Animal( int pPosX, int pPosY, World *pMyWorld ) :
Element::Element(),
Mobile( pPosX, pPosY, pMyWorld ),
Resource()
{
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
