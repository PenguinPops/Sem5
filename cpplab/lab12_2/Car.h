#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <iostream>
using namespace std;

class Car {
    private:
        string model;
        int prodYear;
        float engineCapacity;
    public:
        Car(string model, int prodYear, float engineCapacity);
        void show();
        string getModel();
        int getProdYear();
        float getEngineCapacity();
        void setModel(string model);
        void setProdYear(int prodYear);
        void setEngineCapacity(float engineCapacity);
};

#endif // CAR_H_INCLUDED