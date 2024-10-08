#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string surname1, int age1, int exp1, float salary1)
{
    surname = surname1;
    age = age1;
    exp = exp1;
    salary = salary1;
    cout << "Konstruktor klasy Employee" << endl;
}

Employee::Employee()
{
    cout << "Konstruktor domyślny klasy Employee" << endl;
}

Employee::~Employee()
{
    cout << "Destruktor klasy Employee" << endl;
}

void Employee::show()
{
    cout << "Nazwisko: " << surname << ", wiek: " << age << ", staż pracy: " << exp << ", pensja: " << salary << endl;
}

int Employee::ageEmployment()
{
    return age - exp;
}

string Employee::getSurname()
{
    return surname;
}

int Employee::getAge()
{
    return age;
}

int Employee::getExp()
{
    return exp;
}

float Employee::getSalary()
{
    return salary;
}

