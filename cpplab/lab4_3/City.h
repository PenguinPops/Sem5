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
        void deleteCitizen(string name, string surname);
        void show_citizens();
        void show_city();
        void women();
        void city_citizens();
        void adults();
        void postal_codes();
};

#endif //CITY_H_INCLUDED