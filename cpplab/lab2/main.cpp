// co najważniejsze
// metoda wirtualna gdy np mamy figurę i chcemy obliczyć pole
// to wtedy mamy metode wirtualną pole() w klasie bazowej
// i w klasach pochodnych nadpisujemy tą metodę
// chociaż lepiej skorzystać z czysto wirtualnej
// bo wtedy nie można stworzyć obiektu klasy bazowej, sama figura nie ma przecież pola
// czysto wirtualna to virtual void pole() = 0;
// tylko wirtualna to virtual void pole() {cout << "pole figury";}
// destruktor wirtualny wymagany, virtual ~Figura() {}
// nadpisanie w klasie pochodnej: virtual void pole() override { // np. dla kwadratu cout << "pole kwadratu";}

// kod z laboratorum ( zadanie 1 )

#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
using namespace std;
int main()
{
    Figure *f1 = new Square(4);
    Figure *f2 = new Circle(2);
    f1->calculateArea();
    f1->show();
    f2->calculateArea();
    f2->show();
    Figure *f3;
    Square s1(4);
    f3 = &s1;
    f3->calculateArea();
    f3->show();
    delete f1;
    delete f2;
    delete f3;
    return 0;
}
