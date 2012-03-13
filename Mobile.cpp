#include "Mobile.h"

Mobile::Mobile()
{
    //ctor
}

Mobile::Mobile( int pPosX, int pPosY ) :
Element( pPosX, pPosY ) {}

Mobile::~Mobile(){}

void Mobile::discoverObject() {

}

void Mobile::MoveObject() {
// Discover the objects arround the Mobile Element
    discoverObject();

    int tmpPosX, tmpPosY;
// Indicates if the new coordinates are valide
    bool valide = false;

// If no objects were discovered, move the Mobile Element to a random position
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

    while ( valide == false ) {
// Random direction (1-6)
        int direction = rand() % ( 6 - 1 ) + 1;

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
        if ( tmpPosX < 20 && tmpPosX >= 0 && tmpPosY < 20 && tmpPosY >= 0 )
            valide = true;

// Check if place is free (with map)


    }

// Set the new position
    setMyPosition( tmpPosX, tmpPosY );
    cout << "Hexagon new coordinates: ( " << getMyPosition().GetposX() << ", " << getMyPosition().GetposY() << " )." << endl;
}
