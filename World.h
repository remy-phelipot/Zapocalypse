#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "Element.h"

class World {
    public:
        World();
        virtual ~World();
        vector <Element> *getVectorElement();

    private:
        vector <Element> vectorElement;
        std::map <int, int> mapWorld;
};

#endif // WORLD_H
