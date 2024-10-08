#include "Developer.h"
#include <iostream>
using namespace std;

Developer::Developer(string surname1, int age1, int exp1, float salary1) : Employee(surname1, age1, exp1, salary1)
{
    cout << "Konstruktor klasy Developer" << endl;
}

Developer::Developer()
{
    cout << "Konstruktor domyślny klasy Developer" << endl;
}

Developer::~Developer()
{
    cout << "Destruktor klasy Developer" << endl;
}

void Developer::calculateSalary()
{
    float salary = getSalary();
    if (getExp() < 2)
    {
        salary += 1000;
    }
    else if (getExp() >= 2 && getExp() < 5)
    {
        salary += 2000;
    }
    else
    {
        salary += 3000;
    }
    cout << "Nowa pensja: " << salary << endl;
}

float Developer::calculateBonus(int value)
{
    return value + 0.2 * value * (getSalary() + getExp());
}
