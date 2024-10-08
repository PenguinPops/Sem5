#include <iostream>
#include "Bufor.h"
#include "MeanBufor.h"
#include "MaxBufor.h"

using namespace std;

int main()
{
    Bufor *b1 = new MeanBufor(5);
    b1->add(1);
    b1->add(2);
    b1->add(3);
    b1->add(4);
    b1->add(5);
    b1->show();
    cout << "Średnia: " << b1->calculate() << endl;
    delete b1;

    Bufor *b2 = new MaxBufor(5);
    b2->add(1);
    b2->add(2);
    b2->add(3);
    b2->add(4);
    b2->add(5);
    b2->show();
    cout << "Maksimum: " << b2->calculate() << endl;
    delete b2;

    return 0;
}