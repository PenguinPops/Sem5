#include <iostream>
#include "Figure.h"
#include "Square.h"
using namespace std;
Square::Square(float a1) : Figure()
{
    a = a1;
    cout << "Konstruktor klasy Square" << endl;
}
Square::~Square()
{
    cout << "Destruktor klasy Square" << endl;
}
void Square::calculateArea()
{
    float p = a * a;
    setArea(p);
}

void Square::show()
{
    cout << "Show w klasie Square, pole: " << getArea() << endl;
}

void Square::calculateCircumference()
{
    float o = 4 * a;
    cout << "Obwód kwadratu: " << o << endl;
}