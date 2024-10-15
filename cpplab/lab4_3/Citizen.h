#ifndef CITIZEN_H_INCLUDED
#define CITIZEN_H_INCLUDED

#include <iostream>
using namespace std;

class Citizen {
    private:
        string name;
        string surname;
        int age;
        char sex;
        string postal_code;
    public:
        Citizen();
        Citizen(string name, string surname, int age, char sex, string postal_code);
        void show();
        string getName();
        string getSurname();
        int getAge();
        char getSex();
        string getPostalCode();
};

#endif CITIZEN_H_INCLUDED