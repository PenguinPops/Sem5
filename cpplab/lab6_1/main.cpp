#include <boost/bind/bind.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace boost::placeholders;

void firstArgMod(int &x, int y)
{
    x = x + y;
}
void printF(int x)
{
    cout << x << " ";
}
void contatination(int i1, int i2) // Funkcja łącząca dwa argumenty w jeden napis
{
    cout << i1 << i2 << endl;
}
class Operation
{
public:
    int operator()(int a, int b) // Funktor dwuargumentowy zwracający różnicę argumentów
    {
        return a - b;
    }
    int operator()(char a) // Funktor jednoargumentowy zwracający różnicę argumentu od 'A'
    {
        return (int)a - 32;
    }
};
int addition(int a, int b)
{
    return a + b;
}
int main()
{
    cout << "vec: " << endl;
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int>::iterator iter1 = vec.begin(); // Iterator na początek wektora
    vector<int>::iterator iter2 = vec.end(); // Iterator za koniec wektora
    for_each(iter1, iter2, boost::bind(printF, _1)); // Wyświetlenie elementów wektora, _1 to argument przekazywany do funkcji printF, który jest elementem wektora vec 
    cout << endl
         << "vec - kazdy element zwiekszony o 5: ";
    for_each(iter1, iter2, boost::bind(firstArgMod, _1, 5)); // Zwiększenie każdego elementu o 5 za pomocą funkcji firstArgMod, _1 bierze się stąd, że funkcja firstArgMod przyjmuje dwa argumenty, a _1 to pierwszy z nich, wartości jakie _1 przyjmuje to elementy wektora vec
    for_each(iter1, iter2, boost::bind(printF, _1));
    int count = std::count_if(vec.begin(), vec.end(),
                              boost::bind(std::logical_and<bool>(), // Funkcja zwracająca ilość elementów spełniających oba warunki
                                          boost::bind(std::greater<int>(), _1, 8), // Pierwszy warunek: element większy od 8
                                          boost::bind(std::less_equal<int>(), _1, 10))); // Drugi warunek: element mniejszy lub równy 10
    cout << endl
         << "vec - 8<Elementy<=10 " << count << endl;

    cout << addition(1, 2) << endl;
    int res = boost::bind(addition, _1, _2)(1, 2); // Wywołanie funkcji addition z argumentami 1 i 2
    cout << res << endl;

    int i1 = 1, i2 = 2;
    boost::bind(contatination, _2, _1)(i1, i2); // Wywołanie funkcji contatination z argumentami i1 i i2, ale w odwrotnej kolejności

    Operation ff;
    int x = 1024;
    // Wywołanie funkcji operator() klasy Operation z argumentami x i x
    // po kolei:
    // boost::bind<int> - zwraca funkcję zwracającą int
    // static_cast<int ... - rzutuje wskaźnik na funkcję na wskaźnik na funkcję klasy Operation
    // &Operation::operator() - wskaźnik na funkcję operator() klasy Operation
    // ff - obiekt klasy Operation
    // _1 - pierwszy argument przekazywany do funkcji
    // x - wartość pierwszego argumentu
    cout << "Funktor: " << boost::bind<int>(static_cast<int (Operation::*)(int, int)>(&Operation::operator()), ff, _1, _1)(x) << endl;
    char y = 'a';
    cout << "Funktor: " << boost::bind<int>(static_cast<int (Operation::*)(char)>(&Operation::operator()), ff, _1)(y) << endl;
    return 0;
}