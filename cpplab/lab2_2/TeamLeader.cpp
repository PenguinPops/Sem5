#include "TeamLeader.h"
#include <iostream>
using namespace std;

TeamLeader::TeamLeader(string surname1, int age1, int exp1, float salary1) : Employee(surname1, age1, exp1, salary1)
{
    cout << "Konstruktor klasy TeamLeader" << endl;
}

TeamLeader::TeamLeader()
{
    cout << "Konstruktor domyślny klasy TeamLeader" << endl;
}

TeamLeader::~TeamLeader()
{
    cout << "Destruktor klasy TeamLeader" << endl;
}

void TeamLeader::show()
{
    cout << "Jestem Team Leader z "<< getExp() << " letnim doświadczeniem" << endl;
}

void TeamLeader::calculateSalary()
{
    float salary = getSalary();
    if (getExp() < 2)
    {
        salary += 2000;
    }
    else if (getExp() >= 2 && getExp() < 5)
    {
        salary += 4000;
    }
    else
    {
        salary += 6000;
    }
    cout << "Nowa pensja: " << salary << endl;
}

float TeamLeader::calculateBonus(int value)
{
    return value * (1 + getSalary() + getExp());
}

