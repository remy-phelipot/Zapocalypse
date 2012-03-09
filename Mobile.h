#ifndef MOBILE_H
#define MOBILE_H

#include <cstdlib>

#include "Element.h"

class Mobile : public Element
{
    public:
// Move the Mobile Element to the main point of interest
        void MoveObject();
// Discover the object arround the Mobile Element (called by MoveObject)
        void discoverObject();
        /** Default constructor */
        Mobile();
        Mobile( int, int );
        /** Default destructor */
        virtual ~Mobile();
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

    private:
        int moveRange; //!< Member variable "moveRange"
        int visionRange; //!< Member variable "visionRange"
};

#endif // MOBILE_H
