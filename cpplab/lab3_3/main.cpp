#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    Array<int> a(5);
    a.add(5);
    a.add(2);
    a.add(4);
    a.add(3);
    a.add(1);
    a.show();
    a.sort();
    a.show();
    cout << "Max: " << a.findMax() << endl;

    Array<float> b(5);
    b.add(5.5);
    b.add(2.2);
    b.add(4.4);
    b.add(3.3);
    b.add(1.1);
    b.show();
    b.sort();
    b.show();
    cout << "Max: " << b.findMax() << endl;

    Array<string> c(5);
    c.add("Ania");
    c.add("Basia");
    c.add("Celina");
    c.add("Dorota");
    c.add("Ewa");
    c.show();
    c.sort();
    c.show();
    cout << "Max: " << c.findMax() << endl;
    return 0;
}