#include "Mobile.h"

Mobile::Mobile()
{
    //ctor
}

Mobile::Mobile( int pPosX, int pPosY ) :
Element( pPosX, pPosY ) {}

Mobile::~Mobile()
{
    //dtor
}

void Mobile::discoverObject() {

}

void Mobile::MoveObject() {
// Discover the objects arround the Mobile Element
    discoverObject();

// If no objects were discovered, move the Mobile Element to a random position
// Random direction number
/**
   1
   _
6 / \ 2
5 \_/ 3
   4
 */
    int direction = rand() % ( 6 - 1 ) + 1;
    cout << direction << endl;
    setMyPosition( getMyPosition().GetposX() + GetmoveRange() + direction, getMyPosition().GetposY() + GetmoveRange() + direction );
}
