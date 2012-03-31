#ifndef ANIMAL_H
#define ANIMAL_H

#include "Element.h"
#include "Mobile.h"
#include "Resource.h"
#include "World.h"

#define ANIMAL_IMAGE 'A'
#define ANIMAL_DEFAULT_FOOD 10
#define ANIMAL_DEFAULT_WOOD 0

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
