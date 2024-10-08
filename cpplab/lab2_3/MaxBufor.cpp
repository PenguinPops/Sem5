#include <iostream>
#include "MaxBufor.h"

MaxBufor::MaxBufor() : Bufor()
{
}

MaxBufor::MaxBufor(int size1) : Bufor(size1)
{
}

MaxBufor::~MaxBufor()
{
}

double MaxBufor::calculate()
{
    double max = getTab(0);
    int index = getIndex();
    for (int i = 1; i < index; i++)
    {
        if (getTab(i) > max)
        {
            max = getTab(i);
        }
    }
    return max;
}

void MaxBufor::add(int value)
{
    if (getIndex() < getSize())
    {
        Bufor::add(value);
    }
    else
    {
        std::cout << "Brak miejsca w tablicy" << std::endl;
    }
}