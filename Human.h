#ifndef HUMAN_H
#define HUMAN_H
#include<iostream>
#include"Elements.h"
using namespace std;


class Human : Elements
{
    public:
        Human();

    private:
        string name;
        int health;
        int age;
        int vision;
        int movRange;
        bool isChild;
        int lifeExpectancy;
        bool isContaminated;
        int incubation;
        int dailyFoodConsumption;
        //...
};

#endif // HUMAN_H
