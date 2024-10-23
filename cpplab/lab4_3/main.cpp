#include <iostream>
#include <algorithm>
#include <climits>
#include "City.h"
#include "Citizen.h"

using namespace std;

void showCities(vector<City> c) {
    for (auto& city : c) {
        city.show_city();
        city.show_citizens();
    }
}

void the_most(vector<City> c, int mode) {
    if (mode == 1) {
        City* most_postal_codes_city = nullptr;
        int max_postal_codes = 0;

        for (auto& city : c) {
            int unique_postal_codes = city.postal_codes();
            if (unique_postal_codes > max_postal_codes) {
                max_postal_codes = unique_postal_codes;
                most_postal_codes_city = &city;
            }
        }

        if (most_postal_codes_city) {
            cout << "City with the most unique postal codes: " << most_postal_codes_city->getName() << endl;
        }
    } else if (mode == 2) {
        City* least_population_city = nullptr;
        int min_population = INT_MAX;

        for (auto& city : c) {
            int population = city.city_citizens();
            if (population < min_population) {
                min_population = population;
                least_population_city = &city;
            }
        }

        if (least_population_city) {
            cout << "City with the least population: " << least_population_city->getName() << endl;
        }
    }
}


void statistic(vector<City> c) {
    for (auto& city : c) {
        int total_citizens = city.city_citizens();
        int women_count = city.women();
        int adults_count = city.adults();
        int minors_count = total_citizens - adults_count;
        

        city.show_city();
        cout << "Total citizens: " << total_citizens << ", Women: " << women_count << ", Men: " << (total_citizens - women_count) << endl;
        cout << "Adults: " << adults_count << ", Minors: " << minors_count << endl;
    }
}

void sort_cities(vector<City>& c) {
    sort(c.begin(), c.end(), [](City& a, City& b) {
        return a.city_citizens() < b.city_citizens();
    });
}

int main() {
    Citizen citizen1("John", "Doe", 25, 'M', "20-389");
    Citizen citizen2("Jane", "Doe", 30, 'F', "30-678");
    Citizen citizen3("Anna", "Smith", 17, 'F', "30-678");
    
    City city1("New York");
    city1.addCitizen(citizen1);
    city1.addCitizen(citizen2);
    
    City city2("Los Angeles");
    city2.addCitizen(citizen3);

    vector<City> cities = {city1, city2};

    // Test functions
    showCities(cities);
    cout << "----------" << endl;
    statistic(cities);
    cout << "----------" << endl;
    the_most(cities, 1);  // Miasto z największą liczbą kodów pocztowych
    cout << "----------" << endl;
    sort_cities(cities);
    showCities(cities);

    return 0;
}
