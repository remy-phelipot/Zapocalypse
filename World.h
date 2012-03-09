#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "Position.h"
#include "Element.h"

<<<<<<< HEAD
class World : public vector <Element*> {
=======
class World : public vector<Element*> {
>>>>>>> d117a2ef2198ac9aeae205ab3bdb81d3a0894d4d
    public:
        World();
        virtual ~World();

    private:
        std::map <Position, unsigned> mapWorld;
};

#endif // WORLD_H
