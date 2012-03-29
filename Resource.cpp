#include "Resource.h"

Resource::Resource() {
    woodQuality = 10;
    foodQuality = 10;
}

Resource::Resource( int pFood, int pWood ) {
    foodQuality = pFood;
    woodQuality = pWood;
}
