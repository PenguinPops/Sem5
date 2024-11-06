#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <string>
using namespace std;

class Contact
{
public:
    string imie;
    string nazwisko;
    int wiek;
    string numer;
    string ulica;

    Contact(string imie, string nazwisko, int wiek, string numer, string ulica)
        : imie(imie), nazwisko(nazwisko), wiek(wiek), numer(numer), ulica(ulica) {}

    bool isAdult() const { return wiek >= 18; }
};

#endif // CONTACT_H_INCLUDED
