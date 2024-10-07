#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal() {
    cout << "Konstruktor bez. klasy bazowej - Animal" << endl;
}

Animal::Animal(int limbNr1, string name1) {
    limbNr = limbNr1;
    name = name1;
    protectedAnimal = true;
    cout << "Konstruktor klasy bazowej - Animal" << endl;
}

void Animal::setLimbNr(int limbNr1) {
    limbNr = limbNr1;
}

void Animal::setName(string name1) {
    name = name1;
}

void Animal::setStatus(bool protectedAnimal1) {
    protectedAnimal = protectedAnimal1;
}

int Animal::getLimbNr() {
    return limbNr;
}

string Animal::getName() {
    return name;
}

bool Animal::getStatus() {
    return protectedAnimal;
}

void Animal::giveVoice() {
    cout << "Daje glos" << endl;
}

void Animal::info() {
    cout << "Nazwa: " << name << " liczba konczyn: " << limbNr << " chroniony: " << protectedAnimal << endl;
}

