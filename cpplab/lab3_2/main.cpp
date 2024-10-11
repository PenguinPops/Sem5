template<typename T>
//napisz funkcje szablonową która przyjmuje jako argument tablicę
T findMin(T tab[], int n) {
    T min = tab[0];
    for(int i=1;i<n;i++) {
        if(tab[i]<min) {
            min = tab[i];
        }
    }
    return min;
}

#include <iostream>
using namespace std;

int main() {
    int tab1[5] = {5,2,4,3,1};
    float tab2[5] = {5.5,2.2,4.4,3.3,1.1};
    char tab3[5] = {'e','b','d','c','a'};

    cout << "Min tab1: " << findMin(tab1,5) << endl;
    cout << "Min tab2: " << findMin(tab2,5) << endl;
    cout << "Min tab3: " << findMin(tab3,5) << endl;
    return 0;
}