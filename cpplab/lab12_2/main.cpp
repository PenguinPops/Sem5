#include <iostream>
#include <vector>
#include <algorithm>
#include "Car.h"

using namespace std;

void showSortedByYear(vector<Car>& cars) {
    vector<tuple<int, Car>> sortedCars;
    int i = 1;
    for (auto& car : cars) {
        sortedCars.push_back(make_tuple(i, car));
        ++i;
    }
    sort(sortedCars.begin(), sortedCars.end(), [](tuple<int, Car>& t1, tuple<int, Car>& t2) {
        return get<1>(t1).getProdYear() > get<1>(t2).getProdYear();
    });
    for(auto& t : sortedCars) {
        cout<<"Car "<<get<0>(t)<<":"<<endl;
        get<1>(t).show();
    }
}

void showSortedByCapacity(vector<Car>& cars) {
    vector<tuple<int, Car>> sortedCars;
    int i = 1;
    for (auto& car : cars) {
        sortedCars.push_back(make_tuple(i, car));
        ++i;
    }
    sort(sortedCars.begin(), sortedCars.end(), [](tuple<int,Car>& t1, tuple<int, Car>& t2) {
        return get<1>(t1).getEngineCapacity() > get<1>(t2).getEngineCapacity();
    });
    for(auto& t : sortedCars) {
        cout<<"Car "<<get<0>(t)<<":"<<endl;
        get<1>(t).show();
    }
}

int main() {
    vector<Car> cars;
    cars.push_back(Car("BMW", 2010, 2.0));
    cars.push_back(Car("Audi", 2015, 1.8));
    cars.push_back(Car("Mercedes", 2018, 2.5));

    cout << "Sorted by production year:" << endl;
    showSortedByYear(cars);

    cout << "Sorted by engine capacity:" << endl;
    showSortedByCapacity(cars);

}