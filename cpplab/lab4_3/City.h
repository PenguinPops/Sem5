#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include <iostream>
#include <vector>
#include "Citizen.h"
using namespace std;

class City {
    private:
        vector<Citizen> citizens;
        string city_name;
    public:
        City(string city_name);
        void addCitizen(Citizen c);
        void deleteCitizen(const string &name, const string &surname);
        void show_citizens();
        void show_city();
        string getName();
        int women();
        int city_citizens();
        int adults();
        int postal_codes();
};

#endif //CITY_H_INCLUDED