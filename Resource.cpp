#include "Resource.h"

Resource::Resource() {
    woodQuality = 10;
    foodQuality = 10;
}

Resource::Resource( int pFood, int pWood, int pPosX, int pPosY ) :
Element( pPosX, pPosY ) {
    foodQuality = pFood;
    woodQuality = pWood;
}
