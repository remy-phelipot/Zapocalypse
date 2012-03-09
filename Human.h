#ifndef HUMAN_H
#define HUMAN_H

#include<iostream>
using namespace std;

#include "Mobile.h"

#define HUMAN_IMAGE 'H'

class Human : public Mobile {
    public:
        Human();
        Human( int, int );
        void initHuman();
        bool Action();

    private:
// Read a name in the name file
        string name;
// Healt, 0 to 100
        int health;
// Age
        int age;
// Vision, 0 to 3
        int vision;
// Move range, 0 to 3
        int movRange;
// Boolean, is a children
        bool isChild;
// Random, 0 to 50
        int lifeExpectancy;
// Boolean, was bitten by a zombie
        bool isContaminated;
// Day left before became a zombie
        int incubation;
// Amount of food eaten by day
        int dailyFoodConsumption;
};

#endif // HUMAN_H
