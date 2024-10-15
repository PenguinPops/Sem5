#include "City.h"

City::City(string city_name) : city_name(city_name) {}

void City::addCitizen(Citizen c) {
    citizens.push_back(c);
}

// void City::deleteCitizen(const string &name, const string &surname) {
//     auto it = find_if(citizens.begin(), citizens.end(), [name, surname](const Citizen& citizen) {
//         return citizen.getName() == name && citizen.getSurname() == surname;
//     });
//     if (it != citizens.end()) {
//         citizens.erase(it);
//         cout << "Citizen " << name << " " << surname << " has been removed." << endl;
//     } else {
//         cout << "Citizen not found." << endl;
//     }
// }

void City::show_citizens() {
    cout << "List of citizens:" << endl;
    for (auto& citizen : citizens) {
        citizen.show();
    }
}

void City::show_city() {
    cout<<"City name: "<< city_name <<endl;
}

void City::women() {

}

// void City::city_citizens();
// void City::adults();
// void City::postal_codes();