#include "Citizen.h"

Citizen::Citizen() {}

Citizen::Citizen(string name, string surname, int age, char sex, string postal_code) : name(name), surname(surname), age(age) {}

void Citizen::show() {
    cout << "Name: " << name << " Surname: " << surname << " Age: " << age << " Sex: " << sex << " Postal Code: " << postal_code << endl;
}

string Citizen::getName() {
    return name;
}
string Citizen::getSurname() {
    return surname;
}
int Citizen::getAge() {
    return age;
}
char Citizen::getSex() {
    return sex;
}
string Citizen::getPostalCode() {
    return postal_code;
}

