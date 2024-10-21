#include <iostream>
using namespace std;

template <int divider, typename T>
void showConvertingFromGrams(T elem) {
    if (divider == 10) {
        cout << elem << "g = " << elem / divider << "dag" << endl;
    } else if (divider == 1000) {
        cout << elem << "g = " << elem / divider << "kg" << endl;
    } else if (divider == 1000000) {
        cout << elem << "g = " << elem / divider << "t" << endl;
    } else {
        cout << "Dla podanego typu brak specjalizacji" << endl;
    }
}

// template <float divider, typename T>
// void showConvertingFromGrams(T elem) {
//     cout << elem << "g = " << elem / divider << "mg" << endl;
// }

template <typename T>
void showConvertingFromGrams(T elem) {
    cout << elem << "g = " << elem / 1000 << "kg" << endl;
}

int main() {
    showConvertingFromGrams<100,int>(1000);
    showConvertingFromGrams<100,float>(100.7); 
    showConvertingFromGrams<10,int>(1000.7); 
    showConvertingFromGrams<10,float>(100.7); 
    showConvertingFromGrams<1000, int>(11259);
    showConvertingFromGrams<1000, float>(11259);
    showConvertingFromGrams<1000000,int>(1000000);
    // showConvertingFromGrams<0.001, float>(92148);
    showConvertingFromGrams<int>(1000);
    showConvertingFromGrams<float>(1000.7);
    

    return 0;
}
