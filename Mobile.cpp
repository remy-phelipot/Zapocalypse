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

void Mobile::discoverObject() {

}

void Mobile::MoveObject() {
// Discover the objects arround the Mobile Element
    discoverObject();

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
    int direction = 0;
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

World *Mobile::getMyWorld() {
    return myWorld;
}
