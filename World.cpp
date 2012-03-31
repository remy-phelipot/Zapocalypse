#include "World.h"
#include "Zombie.h"

World::World( int pNbHexagonX, int pNbHexagonY ) {
    nbHexagonX = pNbHexagonX;
    nbHexagonY = pNbHexagonY;

// Variables
    Position tmpPosition;

// Initialise default settings
    GameDate = 0;
    foodQuantity = TEST_FOOD_QUANTITY;
    woodQuantity = TEST_WOOD_QUANTITY;
    foodThresholdAlert = TEST_FOOD_THRESHOLD;
    woodThresholdAlert = TEST_WOOD_THRESHOLD;

// Initialise default human population
    for ( int i = 0 ; i <= TEST_HUMAN_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initialHuman = new Human( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initialHuman );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

// Initialise default animal population
    for ( int i = 0 ; i <= TEST_ANIMAL_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initAnimal = new Animal( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initAnimal );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

// Initialise default zombie population
    for ( int i = 0 ; i <= TEST_ZOMBIE_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initZombie = new Zombie( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initZombie );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

// Initialise default town number
    for ( int i = 0 ; i <= TEST_TOWN_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initTown = new Town( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initTown );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

// Initialise default tree population
    for ( int i = 0 ; i <= TEST_TREE_NUMBER - 1 ; i++ ) {
// Creates random coordinates for the new element
        tmpPosition = newCoordinates();
        Element *initTree = new Tree( tmpPosition.GetposX(), tmpPosition.GetposY(), this );
        push_back( initTree );
// Add the new Position into the map
        mapWorld[tmpPosition] = size() - 1;
    }

    cout << "World initialized.";
    fflush( stdin );
    getch();
}


Position World::newCoordinates() {
// Variables
    int valX;
    int valY;
    bool valide = false;
    Position newPosition( 0, 0 );

    while ( valide == false ) {
// rand()%(b-a)+a
        valX = rand() % nbHexagonX;
        valY = rand() % nbHexagonY;

        if ( valX % 2 == 0 && valY % 2 == 1 ) {
            valY++;
        }

        if ( valX % 2 == 1 && valY % 2 == 0 ) {
            valY--;
        }

        newPosition = Position( valX, valY );

// Check if the coordinates aren't already used in the map
        if ( mapWorld.find( newPosition ) == mapWorld.end() && valX < 20 && valX >= 0 && valY < 20 && valY >= 0 ) {
            valide = true;
        }
    }
    cout << "New coordinates : x=" << valX  << " y=" << valY << endl;
// Return the new Position
    return newPosition;
}


void World::PlayTurn () {
// For each element in the vector, call the Action method
    for ( unsigned int i = 0 ; i <= ( size() - 1 ) ; i++ ) {
        at( i ) -> Action();
// Delete elements if healt <= 0 or age = lifeExpectancy
        if ( at( i ) -> getType() == humanMType || at( i ) -> getType() == humanWType ) {
            cout << "Human " << dynamic_cast<Human*>(at(i))->getAge() << endl;
            /*if ( static_cast<Human*>(at(i)).getAge()==static_cast<Human*>(at(i))->getLifeExpectancy() || static_cast<Human*>(at(i))->getHealt()<=0 ) {
                deleteElement( i );
            }*/
        }
    }
    GameDate++;
}

void World::deleteElement ( int pIndex ) {
    erase( begin() + pIndex );

// Delete everything into the map
    mapWorld.clear();

// Add back everything
    for ( unsigned int i = 0 ; i <= ( size() - 1 ) ; i++ ) {
        mapWorld[ at( i ) -> getMyPosition() ] = i;
    }
}

map <Position, unsigned> *World::getMapWorld() {
    return &mapWorld;
}

void World::eatFood( int pFoodQuantity ) {
    if ( foodQuantity > 0 && ( ( foodQuantity - pFoodQuantity ) > 0 ) ) {
        foodQuantity -= pFoodQuantity;
    }
}

void World::useWood( int pWoodQuantity ) {
    if ( woodQuantity > 0 && ( ( woodQuantity - pWoodQuantity ) > 0 ) ) {
        woodQuantity -= pWoodQuantity;
    }
}

int World::getFood() {
    return foodQuantity;
}

int World::getWood() {
    return woodQuantity;
}

int World::getFoodThreshold() {
    return foodThresholdAlert;
}

int World::getWoodThreshold() {
    return woodThresholdAlert;
}
