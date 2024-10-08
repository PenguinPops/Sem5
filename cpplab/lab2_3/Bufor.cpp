#include "Bufor.h"
#include <iostream>
using namespace std;

Bufor::Bufor()
{
    size = 10;
    tab = new int[size];
    index = 0;
}

Bufor::Bufor(int size1)
{
    size = size1;
    tab = new int[size];
    index = 0;
}

Bufor::~Bufor()
{
    delete[] tab;
}

void Bufor::add(int value)
{
    tab[index] = value;
    index++;
}

int Bufor::getIndex()
{
    return index;
}

int Bufor::getSize()
{
    return size;
}

int Bufor::getTab(int i)
{
    return tab[i];
}

int Bufor::getFirst(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void Bufor::setFirst(int value)
{
    index = value;
}

void Bufor::setTab(int pos, int value)
{
    tab[pos] = value;
}

void Bufor::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

