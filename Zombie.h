#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Human.h"
#include "World.h"

class Zombie : public Human
{
    public:
        Zombie();
        Zombie( int pPoxX, int pPosY, World *pMyWorld );
        virtual ~Zombie();
    protected:
    private:
};

#endif // ZOMBIE_H
