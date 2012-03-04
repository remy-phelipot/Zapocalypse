#include "Human.h"

Human::Human() {
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

Human::Human( int pPosX, int pPosY ) :
Element( pPosX, pPosY ) {
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
