#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <iostream>
#include "Elements.h"
using namespace std;

class World
{
    public:
        World();
        virtual ~World();
    protected:
    private:
        vector <Elements> vElem;
};

#endif // WORLD_H
