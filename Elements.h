#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "Position.h"
#include <iostream>
using namespace std;

class Elements
{
    public:
        Elements();

    private:
        Position pos();
        bool isAlive;

};

#endif // ELEMENTS_H
