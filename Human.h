#ifndef HUMAN_H
#define HUMAN_H

#include<iostream>
using namespace std;

#include "Mobile.h"
#include "World.h"

#define HUMAN_IMAGE_MAN 'M'
#define HUMAN_IMAGE_WOMAN 'W'

class Human : public Mobile {
    public:
        Human();
        Human( int, int, World * );
        void initHuman();
        bool Action();

    private:
// Read a name in the name file
        string name;
// Healt, 0 to 100
        int health;
// Age
        int age;
// Gender : M-W, 1 male, 2 female
        int gender;
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
