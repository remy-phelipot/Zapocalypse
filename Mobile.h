#ifndef MOBILE_H
#define MOBILE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
// Debug
//#include <Windows.h>

using namespace std;

#include "Element.h"

class World;

class Mobile : public virtual Element {
    public:
// Move the Mobile Element to the main point of interest
        void MoveObject();
// Discover the object arround the Mobile Element (called by MoveObject)
        int discoverObject();
        /** Default constructor */
        Mobile();
        Mobile( int, int, World *myWorld );
        /** Default destructor */
        //virtual ~Mobile();
        /** Access moveRange
         * \return The current value of moveRange
         */
        int GetmoveRange() { return moveRange; }
        /** Set moveRange
         * \param val New value to set
         */
        void SetmoveRange(int val) { moveRange = val; }
        /** Access visionRange
         * \return The current value of visionRange
         */
        int GetvisionRange() { return visionRange; }
        /** Set visionRange
         * \param val New value to set
         */
        void SetvisionRange(int val) { visionRange = val; }
        World *getMyWorld();
    private:
        int moveRange; //!< Member variable "moveRange"
        int visionRange; //!< Member variable "visionRange"
        World *myWorld; // Pointer to the world
};

#endif // MOBILE_H
