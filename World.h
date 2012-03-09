#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "Position.h"
#include "Element.h"


class World : public vector <Element*> {
    public:
        World();
        virtual ~World();

    private:
        std::map <Position, unsigned> mapWorld;
};

#endif // WORLD_H
