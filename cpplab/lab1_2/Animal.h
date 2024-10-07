#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <iostream>
using namespace std;

class Animal {
    private:
        int limbNr;
        string name;
        bool protectedAnimal;
    public:
        Animal();
        Animal(int limbNr1, string name1);
        void setLimbNr(int limbNr1);
        void setName(string name1);
        void setStatus(bool protectedAnimal1);
        int getLimbNr();
        string getName();
        bool getStatus();
        void giveVoice();
        void info();
};

#endif // ANIMAL_H_INCLUDED