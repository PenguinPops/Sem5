#include "MeanBufor.h"

MeanBufor::MeanBufor() : Bufor()
{
}

MeanBufor::MeanBufor(int size1) : Bufor(size1)
{
}

MeanBufor::~MeanBufor()
{
}

//calculate() zwraca średnią artytmetyczną z liczb wstawionych do tablicy
double MeanBufor::calculate()
{
    double sum = 0;
    int index = getIndex();
    for (int i = 0; i < index; i++)
    {
        sum += getTab(i);
    }
    return sum / index;
}

