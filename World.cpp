#include "World.h"

World::World()
{
    //ctor
}

World::~World()
{
    //dtor
}

vector <Element> *World::getVectorElement() {
    return &vectorElement;
}
