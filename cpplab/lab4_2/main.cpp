#include <iostream>
#include <deque>
#include <cstdlib>  // dla funkcji rand() i srand()
#include <ctime>    // dla funkcji time()

using namespace std;

int main() {
    srand(time(0));

    // Losujemy liczbę ilosc z przedziału [10, 29]
    int ilosc = rand() % 20 + 10;
    cout << "Liczba wylosowanych liczb: " << ilosc << endl;

    // Tworzymy deque dla przechowywania liczb
    deque<int> lista;

    // Losujemy 'ilosc' liczb z przedziału [-100, 100] i wstawiamy do deque
    for(int i = 0; i < ilosc; ++i) {
        int losowa = rand() % 201 - 100;  // losujemy liczbę z przedziału [-100, 100]
        if (losowa >= 0) {
            lista.push_front(losowa);  // liczby dodatnie lub równe 0 na początek
        } else {
            lista.push_back(losowa);   // liczby ujemne na koniec
        }
    }

    // Wypisanie zawartości listy
    cout << "Zawartość listy: ";
    for (int liczba : lista) {
        cout << liczba << " ";
    }
    cout << endl;

    return 0;
}
