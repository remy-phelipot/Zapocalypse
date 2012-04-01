#ifndef RESOURCE_H
#define RESOURCE_H

#include "Element.h"

class Resource : public virtual Element {
    public:
        Resource();
        Resource( int, int, int, int );
        int getFoodQuality();
        int getWoodQuality();
    private:
        int foodQuality;
        int woodQuality;
};

#endif // RESOURCE_H
