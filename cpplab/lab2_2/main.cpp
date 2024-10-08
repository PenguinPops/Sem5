#include <iostream>
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;

void whoWorkMoreThan5Years(Employee *tab[]) {
    cout<<"Pracownicy pracujący dłużej niż 5 lat: "<<endl;
    for (int i = 0; i < 3; i++) {
        if (tab[i]->getExp() > 5) {
            tab[i]->show();
        }
    }
}

void howManyEarnLessThanMeanBonus(Employee **tab, int size, int bonus) {
    float mean = 0;
    for (int i = 0; i < size; i++) {
        mean += tab[i]->calculateBonus(bonus);
    }
    mean /= size;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i]->calculateBonus(bonus) < mean) {
            counter++;
        }
    }
    cout<<"Pracowników zarabiających mniej niż średnia premia: "<<counter<<endl;
}
int main()
{
    Employee *e1 = new Developer("Kowalski", 30, 3, 5000);
    Employee *e2 = new TeamLeader("Nowak", 35, 5, 7000);
    e1->show();
    e1->calculateSalary();
    e2->show();
    e2->calculateSalary();
    delete e1;
    delete e2;

    Employee *tab[3];
    tab[0] = new Developer("Kowalski", 30, 3, 5000);
    tab[1] = new Developer("Nowak", 35, 5, 7000);
    tab[2] = new TeamLeader("Kowal", 40, 10, 10000);
    whoWorkMoreThan5Years(tab);

    Employee **tab2 = new Employee*[3];
    tab2[0] = new Developer("Kowalski", 30, 3, 5000);
    tab2[1] = new Developer("Nowak", 35, 5, 7000);
    tab2[2] = new TeamLeader("Kowal", 40, 10, 10000);
    howManyEarnLessThanMeanBonus(tab2, 3, 1000);
    for (int i = 0; i < 3; i++) {
        delete tab[i];
        delete tab2[i];
    }


    return 0;
}