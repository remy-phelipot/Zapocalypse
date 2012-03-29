#ifndef ANIMAL_H
#define ANIMAL_H

#define ANIMAL_IMAGE 'A'

#include "Element.h"
#include "Mobile.h"
#include "Resource.h"
#include "World.h"

class Animal : public Mobile, private Resource {
    public:
        Animal();
        Animal( int, int, World* );
    private:
        string name;
        void initAnimal();
        bool Action();
};

#endif // ANIMAL_H
