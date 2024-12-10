#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Elem
{
public:
    shared_ptr<Elem> next;
    weak_ptr<Elem> prev;
    ~Elem()
    {
        cout << "Destruktor Elem" << endl;
    }
};

class Person
{
private:
    string name;
    int age;

public:
    Person(string name1, int age1)
    {
        name = name1;
        age = age1;
    }
    void info()
    {
        cout << name << " " << age << endl;
    }
};

void funDeleter(Person *p)
{
    cout << "usunieta osoba: ";
    p->info();
    delete p;
}

void funcUniqueModify(unique_ptr<int> &uptr) // Przekazywanie przez referencje
{
    *uptr = 112; // Modyfikacja obiektu wskazywanego przez unique_ptr
}

void funUniqueDeleter(int *p)
{
    delete[] p;
    cout << "funUniqueDeleter: usunieta tablica" << endl;
}

unique_ptr<int[]> funUniqueArray(int n)
{
    unique_ptr<int[]> arr(new int[n]);
    for (int i = 0; i < n; i++)
        arr[i] = i + 7;
    return arr;
}

int main()
{

    cout << endl << "unique_ptr" << endl << endl;

    unique_ptr<int> uptr1(new int); // Tworzenie obiektu unique_ptr
    // unique_ptr to inteligentny wskaznik, ktory zarzadza zasobem
    *uptr1 = 12;                                    // Przypisanie wartosci obiektowi wskazywanemu przez unique_ptr
    cout << "Wartosc uptr1: " << *uptr1 << endl;    // Wyswietlenie wartosci obiektu wskazywanego przez unique_ptr
    cout << "Adres uptr1: " << uptr1.get() << endl; // Wyswietlenie adresu obiektu wskazywanego przez unique_ptr
    unique_ptr<int> uptr2;                          // Tworzenie obiektu unique_ptr
    cout << "Przed std::move" << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;
    cout << "Adres uptr2: " << uptr2.get() << endl;
    uptr2 = std::move(uptr1); // Przeniesienie zasobu z uptr1 do uptr2
    cout << "Po std::move: " << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;
    cout << "Adres uptr2: " << uptr2.get() << endl;
    funcUniqueModify(uptr2); // Wywolanie funkcji modyfikujacej obiekt wskazywany przez unique_ptr
    cout << "Wartosc uptr2: " << *uptr2 << endl;
    cout << "Przed reset: Adres uptr2: " << uptr2.get() << endl;
    uptr2.reset();
    cout << "Po reset: Adres uptr2: " << uptr2.get() << endl;

    // -------------------------
    cout << "Tablica unique_ptr" << endl << endl;

    unique_ptr<int[]> tab1(new int[4]);       // Tworzenie obiektu unique_ptr
    cout << "Elementy tablicy tab1:" << endl; // Wyswietlenie elementow tablicy
    for (int i = 0; i < 4; i++)
    {
        tab1[i] = i + 7;
        cout << tab1[i] << endl;
    }
    unique_ptr<int[]> tab3 = funUniqueArray(5); // Wywolanie funkcji zwracajacej obiekt unique_ptr
    cout << "Elementy tablicy tab3:" << endl;
    for (int i = 0; i < 5; i++)
        cout << tab3[i] << endl;
    unique_ptr<int[], void (*)(int *)>                 // Tworzenie obiektu unique_ptr z funkcja zwalniajaca pamiec, skladnia: unique_ptr - typ obiektu, void - typ zwracany, (*) - wskaznik na funkcje, (int *) - argument funkcji. W nawiasach <> podajemy typy argumentow funkcji zwalniajacej pamiec.
    tab2(new int[10], funUniqueDeleter);               // Przekazanie funkcji zwalniajacej pamiec
    vector<unique_ptr<int>> vec;                       // Wektor obiektow unique_ptr
    unique_ptr<int> i1(new int);                       // Tworzenie obiektu unique_ptr
    *i1 = 3;                                           // Przypisanie wartosci obiektowi wskazywanemu przez unique_ptr
    vec.push_back(std::move(i1));                           // Dodanie obiektu unique_ptr do wektora
    cout << "Element w wektorze: " << *vec[0] << endl; // Wyswietlenie elementu wektora

    // -------------------------

    cout << endl << "shared_ptr" << endl << endl;
    shared_ptr<Person> sptr1(new Person("Ola", 32));        // Tworzenie obiektu shared_ptr
    shared_ptr<Person> sptr2(new Person("Ula", 52));        // Tworzenie obiektu shared_ptr
    sptr1->info();                                          // Wywolanie metody obiektu wskazywanego przez shared_ptr
    cout << "Licznik sptr1: " << sptr1.use_count() << endl; // Wyswietlenie licznika shared_ptr
    cout << "Licznik sptr2: " << sptr2.use_count() << endl; // Wyswietlenie licznika shared_ptr
    vector<shared_ptr<Person>> firstInOffice;
    firstInOffice.push_back(sptr1);
    firstInOffice.push_back(sptr2);
    firstInOffice.push_back(sptr2);
    firstInOffice.push_back(sptr1);
    firstInOffice.push_back(sptr2);
    cout << "Po dodaniu do kontenera" << endl;
    cout << "Licznik sptr1: " << sptr1.use_count() << endl;
    cout << "Licznik sptr2: " << sptr2.use_count() << endl;
    for (shared_ptr<Person> ptr : firstInOffice) //
        ptr->info();
    cout << endl;
    firstInOffice.resize(3);
    cout << "Po resize" << endl;
    cout << "Licznik sptr1: " << sptr1.use_count() << endl;
    cout << "Licznik sptr2: " << sptr2.use_count() << endl;
    shared_ptr<Person> sptr3(new Person("Magda", 22), funDeleter); // Tworzenie obiektu shared_ptr z funkcja zwalniajaca pamiec
    sptr3->info();

    cout << endl << "weak_ptr" << endl << endl;

    shared_ptr <Elem> el1 (new Elem); // Tworzenie obiektu shared_ptr
    shared_ptr <Elem> el2 (new Elem); // Tworzenie obiektu shared_ptr
    el1->next = el2;
    el2->prev = el1;
    shared_ptr<Elem> tempEl(el2->prev);
    cout <<"Adres: " <<tempEl<< endl;
    return 0;
}