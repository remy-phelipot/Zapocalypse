#include "Human.h"

Human::Human() {
    initHuman();
}

Human::Human( int pPosX, int pPosY ) :
Element( pPosX, pPosY ) {
    initHuman();
}

// initHuman called by the constructor
void Human::initHuman () {
// Read a new name in the name file
    name = "BasicHuman";
    health = 100;
    age = 0;
// Random vision
    vision = 1;
    movRange = 1;
    isChild = true;
    lifeExpectancy = 75;
    isContaminated = false;
    incubation = 0;
    dailyFoodConsumption = 10;

// Image of a Human : H
    setImage( HUMAN_IMAGE );
}

bool Human::Action() {
    cout << "Human basic action, moving..." << endl;
    setMyPosition( getMyPosition().GetposX() + 1, getMyPosition().GetposY() + 1 );

// No problem
    return true;
// If there is a problem, return false and delete the element (fail)
}
