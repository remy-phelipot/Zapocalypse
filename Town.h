#ifndef TOWN_H
#define TOWN_H

#include "Resource.h"
#include "World.h"

#define TOWN_IMAGE 'T'
#define TOWN_DEFAULT_FOOD 20
#define TOWN_DEFAULT_WOOD 10

class Town : public Resource {
    public:
        Town();
        Town( int, int, World* );

    private:
        string name;
        void initTown();
        bool Action();
};

#endif // TOWN_H
