#include "Contacts.h"
#include <iostream>
using namespace std;

int main()
{
    Contacts addressBook;

  
    cout << "Dodawanie kontaktów...\n";
    addressBook.addContact("Jan", "Kowalski", 25, "123456789", "Ulica Główna");
    addressBook.addContact("Anna", "Nowak", 30, "987654321", "Ulica Główna");
    addressBook.addContact("Alicja", "Wiśniewska", 17, "111222333", "Ulica Dębowa");
    addressBook.addContact("Bartosz", "Lewandowski", 45, "444555666", "Ulica Sosnowa");
    addressBook.addContact("Karol", "Kowalski", 20, "333444555", "Ulica Główna");

    
    cout << "\nWyświetlanie wszystkich kontaktów:\n";
    addressBook.showContacts();

    
    cout << "\nPróba dodania kontaktu z duplikatem numeru:\n";
    addressBook.addContact("Duplikat", "Kontakt", 50, "123456789", "Ulica Lipowa");

    
    cout << "\nWyszukiwanie kontaktów z ulicy 'Ulica Główna':\n";
    addressBook.searchByStreet("Ulica Główna");

    
    cout << "\nWyszukiwanie kontaktów w przedziale wiekowym 18 do 30 lat:\n";
    addressBook.searchByAge(18, 30);

    
    cout << "\nWyszukiwanie kontaktu o numerze '444555666':\n";
    addressBook.searchByNumber("444555666");

    
    cout << "\nZmiana ulicy 'Ulica Główna' na 'Ulica Krakowska':\n";
    addressBook.changeStreet("Ulica Główna", "Ulica Krakowska");

    
    cout << "\nWyświetlanie wszystkich kontaktów po zmianie ulicy:\n";
    addressBook.showContacts();

    
    cout << "\nLiczba osób pełnoletnich w książce adresowej:\n";
    addressBook.countAdults();

    
    cout << "\nLiczba unikalnych nazwisk:\n";
    addressBook.countUniqueSurnames();

    
    cout << "\nUsunięcie kontaktu o numerze '987654321':\n";
    addressBook.removeContact("987654321");

    
    cout << "\nWyświetlanie wszystkich kontaktów po usunięciu:\n";
    addressBook.showContacts();

    return 0;
}
