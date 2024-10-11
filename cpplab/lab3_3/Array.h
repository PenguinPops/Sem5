#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Array {
    private:
        T *tab;
        int maxSize;
        int firstFree;
    public:
        Array(int n);
        Array();
        ~Array();
        void sort();
        T findMax();
        void show();
        void add(T value);
        T getElement(int index);
};


template<typename T>
Array<T>::Array(int n) {
    maxSize = n;
    firstFree = 0;
    tab = new T[maxSize];
}

template<typename T>
Array<T>::Array() {
    maxSize = 10;
    firstFree = 0;
    tab = new T[maxSize];
}

template<typename T>
Array<T>::~Array() {
    delete [] tab;
}

template<typename T>
void Array<T>::sort() {
    for(int i=0;i<firstFree-1;i++) {
        for(int j=0;j<firstFree-1;j++) {
            if(tab[j]>tab[j+1]) {
                T temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    return;
}

template<typename T>
T Array<T>::findMax() {
    T max = tab[0];
    for(int i=1;i<firstFree;i++) {
        if(tab[i]>max) {
            max = tab[i];
        }
    }
    return max;
}

template<typename T>
void Array<T>::show() {
    for(int i=0;i<firstFree;i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
    return;
}

template<typename T>
void Array<T>::add(T value) {
    if(firstFree<maxSize) {
        tab[firstFree] = value;
        firstFree++;
    }
    return;
}

template<typename T>
T Array<T>::getElement(int index) {
    if(index>=0 && index<firstFree) {
        return tab[index];
    }
    return T();
}

template<>
void Array<string>::sort() {
    for(int i=0;i<firstFree-1;i++) {
        for(int j=0;j<firstFree-1;j++) {
            if(tab[j].length()>tab[j+1].length()) {
                string temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    return;
}

template<>
string Array<string>::findMax() {
    string max = tab[0];
    for(int i=1;i<firstFree;i++) {
        if(tab[i].length()>max.length()) {
            max = tab[i];
        }
    }
    return max;
}



#endif // ARRAY_H_INCLUDED