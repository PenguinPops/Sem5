// Zadanie 1
#include <iostream>
using namespace std;

class Bazowa {
protected:
    int liczba;
public:
    Bazowa(int liczba) : liczba(liczba) {}

    void print() {
        cout << "liczba bazowa: " << liczba << endl;
    }

    virtual void show() {
        cout << "liczba bazowa virtual: " << liczba << endl;
    }

    //virtual void show() =0; //czysto wirtualna
};

class Pochodna : public Bazowa {
public:
//jesli jest cos po : to jest to lista inicjalizacyjna
    Pochodna(int liczba) : Bazowa(liczba * 100) {}
//zrob to bez listy inicjalizacyjnej
    // Pochodna(int liczba) {
    //     this->liczba = liczba * 100;
    // }
    void print(){
        cout << "liczba pochodna: " << liczba << endl;
    }

    void show() override {
        cout << "liczba pochodna virtual: " << liczba << endl;
    }
};

int main() {
    Bazowa b(10);
    Pochodna p(10);

    cout << "Wywołanie metod obiektu Bazowa:" << endl;
    b.print();
    b.show();

    cout << "\nWywołanie metod obiektu Pochodna:" << endl;
    p.print();
    p.show();

    // cout << "\nPolimorfizm z wskaźnikiem do klasy bazowej:" << endl;
    // Bazowa* ptr = &p;
    // ptr->print();
    // ptr->show();

    return 0;
}