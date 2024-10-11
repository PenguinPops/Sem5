// template <typename T>
// void mySwap(T &a, T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// int main() {
//     int a= 6;
//     int b = 8;
//     cout<< "Przed zamiana: a = " << a << ", b = " << b << endl;
//     mySwap(a, b);
//     cout<< "Po zamianie: a = " << a << ", b = " << b << endl;

//     char c = 'A';
//     char d = 'B';
//     cout<< "Przed zamiana: c = " << c << ", d = " << d << endl;
//     mySwap(c, d);
//     cout<< "Po zamianie: c = " << c << ", d = " << d << endl;
//     return 0;
// }

template<typename T>
void showAll(T* tab[], int n) {
    for(int i=0;i<n;i++) tab[i]->show();
}

#include <iostream>
#include "Adding.h"
#include "Student.h"
using namespace std;

int main() {
    Adding<int> a1(5);
    a1.add(6);
    a1.show();

    Adding<string> a2("Hello");
    a2.add(" World");
    a2.show();

    Student<float> s(5,"Ala");
    s.showMark();
    Student<int> s1(5,"Ala");
    s1.showMark();
    Student<string> s2(5,"Ala");
    s2.showMark();

    Adding<int> **arrAdd; //dynamiczna tablica dynamicznych obiektow
    arrAdd = new Adding<int>*[3]; //twozenie tablicy wskaznikow
    for(int i = 0; i<3;i++) {
        arrAdd[i] = new Adding<int>(i); //tworzenie obiektow
    }
    showAll(arrAdd,3);

    Student<string>* arrStu[2]; //statyczna tablica dynamicznych obiektow
    for(int i = 0; i<2;i++) {
        arrStu[i] = new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,2);

    for(int i=0; i<3;i++) {
        delete arrAdd[i];
    }

    for(int i=0; i<2;i++) {
        delete arrStu[i];
    }



    return 0;
}



