#include "Mobile.h"
#include "World.h"

Mobile::Mobile() {
    cout << "Mobile : default constructor." << endl;
}

Mobile::Mobile( int pPosX, int pPosY, World *pMyWorld ) :
Element( pPosX, pPosY ) {
    cout << "Mobile : parameterized constructor, x=" << pPosX << " y=" << pPosY << endl;
    myWorld=pMyWorld;
}


// Interaction with other elements
int Mobile::discoverObject() {
    int direction = 0;

// Discover all elements, put it into a table
// then choose wich one is the best and deal with the element
    int tabElements[ 6 ];
    int nbElements = 0;

// Check in every direction
    Position tmpPos( getMyPosition().GetposX(), getMyPosition().GetposY() );

// 1
    tmpPos.SetposY( getMyPosition().GetposY() - 2 );
    if ( getMyPosition().GetposX() < 20 && getMyPosition().GetposX() >= 0 && getMyPosition().GetposY() < 20 && getMyPosition().GetposY() >= 0 && myWorld->getMapWorld()->count(tmpPos) == 1 ) {
// If its not free, save the vector index
        tabElements[ nbElements ] = myWorld->getMapWorld()->find(tmpPos)->second;
        cout << "Finds element : " << tabElements[ nbElements ] << endl;
        nbElements++;
    }

// 2
    tmpPos.SetposX( getMyPosition().GetposX() + 1 );
    tmpPos.SetposY( getMyPosition().GetposY() - 1 );
    if ( getMyPosition().GetposX() < 20 && getMyPosition().GetposX() >= 0 && getMyPosition().GetposY() < 20 && getMyPosition().GetposY() >= 0 && myWorld->getMapWorld()->count(tmpPos) == 1 ) {
// If its not free, save the vector index
        tabElements[ nbElements ] = myWorld->getMapWorld()->find(tmpPos)->second;
        cout << "Finds element : " << tabElements[ nbElements ] << endl;
        nbElements++;
    }

// 3
    tmpPos.SetposX( getMyPosition().GetposX() + 1 );
    tmpPos.SetposY( getMyPosition().GetposY() + 1 );
    if ( getMyPosition().GetposX() < 20 && getMyPosition().GetposX() >= 0 && getMyPosition().GetposY() < 20 && getMyPosition().GetposY() >= 0 && myWorld->getMapWorld()->count(tmpPos) == 1 ) {
// If its not free, save the vector index
        tabElements[ nbElements ] = myWorld->getMapWorld()->find(tmpPos)->second;
        cout << "Finds element : " << tabElements[ nbElements ] << endl;
        nbElements++;
    }

// 4
    tmpPos.SetposX( getMyPosition().GetposX() + 0 );
    tmpPos.SetposY( getMyPosition().GetposY() + 2 );
    if ( getMyPosition().GetposX() < 20 && getMyPosition().GetposX() >= 0 && getMyPosition().GetposY() < 20 && getMyPosition().GetposY() >= 0 && myWorld->getMapWorld()->count(tmpPos) == 1 ) {
// If its not free, save the vector index
        tabElements[ nbElements ] = myWorld->getMapWorld()->find(tmpPos)->second;
        cout << "Finds element : " << tabElements[ nbElements ] << endl;
        nbElements++;
    }

// 5
    tmpPos.SetposX( getMyPosition().GetposX() - 1 );
    tmpPos.SetposY( getMyPosition().GetposY() + 1 );
    if ( getMyPosition().GetposX() < 20 && getMyPosition().GetposX() >= 0 && getMyPosition().GetposY() < 20 && getMyPosition().GetposY() >= 0 && myWorld->getMapWorld()->count(tmpPos) == 1 ) {
// If its not free, save the vector index
        tabElements[ nbElements ] = myWorld->getMapWorld()->find(tmpPos)->second;
        cout << "Finds element : " << tabElements[ nbElements ] << endl;
        nbElements++;
    }

// 6
    tmpPos.SetposX( getMyPosition().GetposX() - 1 );
    tmpPos.SetposY( getMyPosition().GetposY() - 1 );
    if ( getMyPosition().GetposX() < 20 && getMyPosition().GetposX() >= 0 && getMyPosition().GetposY() < 20 && getMyPosition().GetposY() >= 0 && myWorld->getMapWorld()->count(tmpPos) == 1 ) {
// If its not free, save the vector index
        tabElements[ nbElements ] = myWorld->getMapWorld()->find(tmpPos)->second;
        cout << "Finds element : " << tabElements[ nbElements ] << endl;
        nbElements++;
    }

    switch ( getType() ) {

// MAN : can reproduce if WOMAN have been discovered and resources are available
// Can kill animals
// Can cut trees
        case humanMType:
// Check element type in vector
            for ( int i = 0 ; i <= nbElements - 1 && direction == 0 ; i++ ) {
                if ( ( myWorld->at( tabElements[ i ] )->getType() == humanWType ) &&
                    myWorld->getFood()>myWorld->getFoodThreshold() ) {
// Create a human
// Creates random coordinates for the new element
                    Position tmpPosition = myWorld -> newCoordinates();
                    Element *initialHuman = new Human( tmpPosition.GetposX(), tmpPosition.GetposY(), myWorld );
                    myWorld -> push_back( initialHuman );
// Add the new Position into the map
                    myWorld -> getMapWorld() -> insert( pair<Position, unsigned>(tmpPos, myWorld -> size() - 1) );
                    direction++;
                }
                else if ( myWorld->at( tabElements[ i ] )->getType() == rabbitType || myWorld->at( tabElements[ i ] )->getType() == townType ) {
// Take resource and delete element
                    cout << "Town or Rabbit..." << endl;
                    Element *element1 = myWorld->at( tabElements[i] );
                    Resource *resource1 = dynamic_cast<Resource*>(element1);
// Set wood and food
                    myWorld->addFood( resource1->getFoodQuality() );
                    myWorld->addWood( resource1->getWoodQuality() );
// Delete element
                    myWorld->deleteElement( tabElements[i] );
                    direction++;
                }
            }
            break;


// WOMAN : can reproduce if MAN have been discovered and resources are available
// Can kill animals
        case humanWType:
            for ( int i = 0 ; i <= nbElements - 1 && direction == 0 ; i++ ) {
                if ( ( myWorld->at( tabElements[ i ] )->getType() == humanMType ) &&
                    myWorld->getFood()>myWorld->getFoodThreshold() ) {
// Create a human
// Creates random coordinates for the new element
                    Position tmpPosition = myWorld -> newCoordinates();
                    Element *initialHuman = new Human( tmpPosition.GetposX(), tmpPosition.GetposY(), myWorld );
                    myWorld -> push_back( initialHuman );
// Add the new Position into the map
                    myWorld -> getMapWorld() -> insert( pair<Position, unsigned>(tmpPos, myWorld -> size() - 1) );
                    direction++;
                }
                else if ( myWorld->at( tabElements[ i ] )->getType() == rabbitType || myWorld->at( tabElements[ i ] )->getType() == townType ) {
// Take resource and delete element
                    cout << "Town or Rabbit..." << endl;
                    Element *element1 = myWorld->at( tabElements[i] );
                    Resource *resource1 = dynamic_cast<Resource*>(element1);
// Set wood and food
                    myWorld->addFood( resource1->getFoodQuality() );
                    myWorld->addWood( resource1->getWoodQuality() );
// Delete element
                    myWorld->deleteElement( tabElements[i] );
                    direction++;
                }
            }
            break;

        default:
            cout << "Other..." << endl;
            break;
    }
    return direction;
}


void Mobile::MoveObject() {
// Discover the objects arround the Mobile Element
    int direction = discoverObject();

    int tmpPosX, tmpPosY;
    Position tmpPos( 0, 0 );
// Indicates if the new coordinates are valide
    bool valide = false;
    int i = 0;

// If no objects were discovered, moves the Mobile Element to a random position
// Random direction number
/**
   _
  /1\_
/6\_/2\
\_/ \_/
/5\_/3\
\_/4\_/
  \_/

 */
    if ( direction == 0 ) {
        while ( valide == false && i < 10 ) {
    // Random direction (1-6)
            direction = rand() % 6  + 1;

            tmpPosX = getMyPosition().GetposX();
            tmpPosY = getMyPosition().GetposY();

            switch( direction ) {
                case 1:
                    tmpPosY -= 2;
                    break;

                case 2:
                    tmpPosX += 1;
                    tmpPosY -= 1;
                    break;

                case 3:
                    tmpPosX += 1;
                    tmpPosY += 1;
                    break;

                case 4:
                    tmpPosY += 2;
                    break;

                case 5:
                    tmpPosX -= 1;
                    tmpPosY += 1;
                    break;

                case 6:
                    tmpPosX -= 1;
                    tmpPosY -= 1;
                    break;
            }
    // Check if out of bounds
            if ( tmpPosX < 20 && tmpPosX >= 0 && tmpPosY < 20 && tmpPosY >= 0 ) {
                tmpPos = Position( tmpPosX, tmpPosY );
                if ( myWorld -> getMapWorld() -> find( tmpPos ) == myWorld -> getMapWorld() -> end() ) {
    // Check if place is free (with map)
                    valide = true;
                }
            }
            i++;
        }

        if ( valide == true ) {
    // Get the vector index into the map, save it and delete the element into the map
            tmpPos = Position( getMyPosition().GetposX(), getMyPosition().GetposY() );
            int vectorIndex = myWorld -> getMapWorld() -> find( tmpPos ) -> second;
            myWorld -> getMapWorld() -> erase( tmpPos );

    // Set the new position
            setMyPosition( tmpPosX, tmpPosY );
            tmpPos = Position( getMyPosition().GetposX(), getMyPosition().GetposY() );
    // Insert the new coordinates into the map
            myWorld -> getMapWorld() -> insert( pair<Position, unsigned>(tmpPos, vectorIndex));
            cout << "Hexagon " << direction << " new coordinates: ( " << getMyPosition().GetposX() << ", " << getMyPosition().GetposY() << " )." << endl;
        }
        else {
            cout << "Can't move object..." << endl;
            //Sleep( 3000 );
        }
    }
}


World *Mobile::getMyWorld() {
    return myWorld;
}
