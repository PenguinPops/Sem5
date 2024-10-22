#include "Citizen.h"

Citizen::Citizen() {}

Citizen::Citizen(string name, string surname, int age, char sex, string postal_code) : name(name), surname(surname), age(age), sex(sex), postal_code(postal_code) {}

void Citizen::show() {
    cout << "Name: " << name << " Surname: " << surname << " Age: " << age << " Sex: " << sex << " Postal Code: " << postal_code << endl;
}

string Citizen::getName() const {
    return name;
}
string Citizen::getSurname() const {
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

