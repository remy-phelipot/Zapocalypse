#include "Human.h"

Human::Human() {
    initHuman();
}

Human::Human( int pPosX, int pPosY, World *pMyWorld ) :
Element ( pPosX, pPosY ),
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
// Random life expectancy
    lifeExpectancy = rand() % 75 + 1;

    isContaminated = false;
    incubation = 0;
    dailyFoodConsumption = 10;
// Random gender : 1 or 2
    gender = rand() % 2 + 1;
    cout << "Gender : " << gender << endl;

// Image of a Human
// Type of a Human
    if ( gender == 1 ) {
        setImage( HUMAN_IMAGE_MAN );
        setType( humanMType );
    }
    else {
        setImage( HUMAN_IMAGE_WOMAN );
        setType( humanWType );
    }
}

bool Human::Action() {
    cout << "Human basic action, moving..." << endl;
    MoveObject();

// Increase age
    age++;

// No problem
    return true;
// If there is a problem, return false and delete the element (fail)
}
