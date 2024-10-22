#include "City.h"
#include <unordered_map>
#include <algorithm>

City::City(string city_name) : city_name(city_name) {}

void City::addCitizen(Citizen c) {
    citizens.push_back(c);
}

#include <algorithm> // Include the <algorithm> header for find_if

void City::deleteCitizen(const string& name, const string& surname) {
    auto it = find_if(citizens.begin(), citizens.end(), [&](const Citizen& citizen) {
        return citizen.getName() == name && citizen.getSurname() == surname;
    });

    if (it != citizens.end()) {
        citizens.erase(it);
        cout << "Citizen " << name << " " << surname << " has been removed from " << city_name << "." << endl;
    } else {
        cout << "Citizen " << name << " " << surname << " not found in " << city_name << "." << endl;
    }
}


void City::show_citizens() {
    cout << "List of citizens:" << endl;
    for (auto& citizen : citizens) {
        citizen.show();
    }
}

void City::show_city() {
    cout << "City name: " << city_name << endl;
}

string City::getName() {
    return city_name;
}

int City::women() {
    int count = 0;
    for (auto& citizen : citizens) {
        if (citizen.getSex() == 'F') {
            count++;
        }
    }
    return count;
}

int City::city_citizens() {
    return citizens.size();
}

int City::adults() {
    int count = 0;
    for (auto& citizen : citizens) {
        if (citizen.getAge() >= 18) {
            count++;
        }
    }
    return count;
}

int City::postal_codes() {
    unordered_map<string, int> postalCodeMap;
    for (auto& citizen : citizens) {
        postalCodeMap[citizen.getPostalCode()]++;
    }

    cout << "Postal codes in " << city_name << ":" << endl;
    for (auto& pair : postalCodeMap) {
        cout << pair.first << " -> " << pair.second << " citizens" << endl;
    }
    
    return postalCodeMap.size();  // Return the number of unique postal codes
}


