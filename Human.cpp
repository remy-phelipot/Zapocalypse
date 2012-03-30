#include "Human.h"

Human::Human() {
    initHuman();
}

Human::Human( int pPosX, int pPosY, World *pMyWorld ) :
Mobile( pPosX, pPosY, pMyWorld ) {
    initHuman();
}

// initHuman called by the constructor
void Human::initHuman () {
// Read a new name in the name file
    name = "BasicHuman";
    health = 100;
    age = 0;
// Random visionRange
    SetvisionRange( 1 );
// Random moveRange
    SetmoveRange( 1 );
    isChild = true;
    lifeExpectancy = 75;
    isContaminated = false;
    incubation = 0;
    dailyFoodConsumption = 10;

// Image of a Human : H
    setImage( HUMAN_IMAGE );
// Type of a Human
    setType( humanMType );
}

bool Human::Action() {
    cout << "Human basic action, moving..." << endl;
    MoveObject();
// No problem
    return true;
// If there is a problem, return false and delete the element (fail)
}
