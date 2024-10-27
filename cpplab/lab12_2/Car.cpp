#include "Car.h"

Car::Car(string model, int prodYear, float engineCapacity) : model(model), prodYear(prodYear), engineCapacity(engineCapacity) {}

void Car::show() {
    cout << "Model: " << model << endl;
    cout << "Production year: " << prodYear << endl;
    cout << "Engine capacity: " << engineCapacity << endl;
}

string Car::getModel() {
    return model;
}

int Car::getProdYear() {
    return prodYear;
}

float Car::getEngineCapacity() {
    return engineCapacity;
}

void Car::setModel(string model) {
    this->model = model;
}

void Car::setProdYear(int prodYear) {
    this->prodYear = prodYear;
}

void Car::setEngineCapacity(float engineCapacity) {
    this->engineCapacity = engineCapacity;
}
