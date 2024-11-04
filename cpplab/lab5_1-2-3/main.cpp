#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;



char znajdzRozniceMultiSet(const string &s1, const string &s2)
{
    multiset<char> c1(s1.begin(), s1.end());
    multiset<char> c2(s2.begin(), s2.end());

    for (char c : c2)
    {
        auto it = c1.find(c);
        if (it != c1.end()) // Jeśli znak istnieje w c1, usuwamy jego wystąpienie
        {
            c1.erase(it); // Usuwamy jeden wystąpienie tego znaku
        }
        else
        {
            return c; // Jeśli znak nie istnieje w c1, to jest to znak dodany
        }
    }

    return '\0'; // Powinno być niemożliwe do osiągnięcia
}


// Funkcja do wyświetlania elementów zbioru
template <typename T>
void show(const set<T> &s)
{
    for (const auto &elem : s)
    {
        cout << elem << " ";
    }
    cout << endl;
}

// Funkcja do wyznaczania różnicy zbiorów
template <typename T1, typename T2>
void alt_wykl(const set<T1> &s1, const set<T2> &s2)
{
    set<string> sDiffer;

    // Dodajemy elementy z pierwszego zbioru, konwertując je na stringi
    for (const auto &e : s1)
    {
        sDiffer.insert(to_string(e)); // Konwersja int na string
    }

    // Usuwamy elementy, które są w drugim zbiorze (string)
    for (const auto &e : s2)
    {
        sDiffer.erase(e); // Elementy są już stringami, nie trzeba konwertować
    }

    show(sDiffer); // Wyświetlanie różnicy
}

template <typename T1, typename T2>
double alt_wykl2(const set<T1> &s1, const set<T2> &s2) 
{
    double sum = 0;
    set<double> sDiffer;
    pair<set<double>::iterator, bool> r;
    for(const auto &e : s1) {
        r = sDiffer.insert(e);
        if(r.second) sum+=e;
    }
    for(const auto &e : s2) {
        r = sDiffer.insert(e);
        if(!r.second) { sDiffer.erase(e); sum-=e; };
        if(r.second) sum+=e;
    }
    return sum;
}


pair<int, int> duplikat(vector<int> &v)
{
    set<int> s;
    pair<set<int>::iterator, bool> res; // Iterator i flaga
    res.second = true;                  // Inicjalizacja flagi
    while (res.second && !v.empty())
    {
        res = s.insert(v.back()); // Dodanie elementu z końca wektora
        v.pop_back();             // Usunięcie elementu z wektora
    }
    pair<int, int> duplikat;
    duplikat.first = *(res.first); // Element duplikowany

    // Przenosimy resztę elementów do zbioru
    while (!v.empty())
    {
        s.insert(v.back());
        v.pop_back();
    }

    // Obliczamy sumę wszystkich elementów w zbiorze
    int sum = 0;
    for (auto e : s)
    {
        sum += e;
    }

    duplikat.second = sum; // Przypisanie sumy elementów do `duplikat.second`
    return duplikat;
}

int main()
{
    cout << endl
         << "Zadanie 5.1" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 3}; // Przykładowy wektor z duplikatem
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    pair<int, int> d = duplikat(v);
    cout << "Wartość powtórzona: " << d.first << ", Suma elementów unikalnych: " << d.second << endl;
    cout << endl
         << "Zadanie 5.2" << endl;
    // set<int> s1 = {1, 2, 3, 4, 5};
    // set<string> s2 = {"1", "3", "A", "B", "Ania"};
    // show(s1);
    // show(s2);
    // cout << "Tylko w pierwszym zbiorze: " << endl;
    // alt_wykl(s1, s2);

    set<int> s3 = {1, 2, 3};
    set<int> s4 = {3, 4, 5};
    double a = alt_wykl2(s3, s4);
    cout << "Suma elementów unikatowych tylko ze zbioru jednego albo drugiego: " << a << endl;

    string str1 = "aabc";
    string str2 = "cadab";
    cout << endl
         << "Zadanie 5.3" << endl;
    char dodanyZnak = znajdzRozniceMultiSet(str1, str2);
    // dodanyZnak = znajdzRozniceMap(str1, str2);
    cout << "Dla stringów: " << str1 << " " << str2 << endl
         << "Dodany znak to: " << dodanyZnak << endl;

    return 0;
}

