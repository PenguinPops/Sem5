// Zadanie 2
#include <iostream>
#include <type_traits>
using namespace std;

template<int divider, typename T>
void showConvertingFromGrams(T elem) {
    if constexpr (is_same_v<T, int> || is_same_v<T, float>) {
        cout << elem << "g = " << (elem / static_cast<T>(divider)) << " dag" << endl;
    } else {
        cout << "Dla podanego typu brak specjalizacji" << endl;
    }
}

int main() {
    showConvertingFromGrams<100>(1000); // int case
    showConvertingFromGrams<100>(100.7f); // float case
    showConvertingFromGrams<100>('a'); // unsupported type
    return 0;
}