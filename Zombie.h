#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Human.h"

#define ZOMBIE_IMAGE 'Z'

class World;

class Zombie : public Human {
    public:
        Zombie();
        Zombie( int, int, World* );
        bool Action();
    private:
        bool onMove;
};

#endif // ZOMBIE_H
