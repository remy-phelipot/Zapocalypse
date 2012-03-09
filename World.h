#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "Element.h"

class World : public vector <Element*> {
    public:
        World();
        virtual ~World();

    private:
        vector <Element*> vectorElement;
        std::map <int, int> mapWorld;
};

#endif // WORLD_H
