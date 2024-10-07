#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include <iostream>
#include "Animal.h"
using namespace std;

class Cat: public Animal {
    private:
        //levelofmousehunting, from 1 to 10
        int levelOfMouseHunting;
        //mice[5], array of 5 mice hunted by year
        int mice[5];
    public:
        Cat(int limbNr1, string name1);
        Cat();
        void initMice();
        void initCat(int limbNr1, string name1, int levelOfMouseHuntingSkills1);
        void setLevelOfMouseHunting(int value);
        int getLevelOfMouseHunting();
        int getMice(int index);
        void giveVoice();
        void info();
};

#endif // CAT_H_INCLUDED
