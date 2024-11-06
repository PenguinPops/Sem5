#ifndef CONTACTS_H_INCLUDED
#define CONTACTS_H_INCLUDED

#include "Contact.h"
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <iostream>
#include <set>
using namespace std;
using namespace boost::multi_index;

// Define indices for the multi_index_container
struct by_number {};
struct by_street {};
struct by_age;

class Contacts
{
public:
    // Define the multi_index_container for contacts
    typedef multi_index_container<
        Contact,
        indexed_by<
            hashed_unique<tag<by_number>, member<Contact, string, &Contact::numer>>,
            hashed_non_unique<tag<by_street>, member<Contact, string, &Contact::ulica>>,
            ordered_non_unique<tag<by_age>, member<Contact, int, &Contact::wiek>>>>
        contact_set;

    contact_set contacts;

    Contacts() = default;
    ~Contacts() = default;

    // Function to add a contact, ensuring unique phone numbers
    void addContact(string imie, string nazwisko, int wiek, string numer, string ulica)
    {
        auto& number_index = contacts.get<by_number>();
        if (number_index.find(numer) == number_index.end()) // index.end() returns an iterator to the end of the index, so no matches were found
        {
            contacts.emplace(imie, nazwisko, wiek, numer, ulica); // emplace - construct and insert in one step
        }
        else
        {
            cout << "Contact with this number already exists.\n";
        }
    }

    // Function to remove a contact by phone number
    void removeContact(string numer)
    {
        auto& number_index = contacts.get<by_number>();
        auto it = number_index.find(numer);
        if (it != number_index.end())
        {
            number_index.erase(it);
            cout << "Contact removed.\n";
        }
        else
        {
            cout << "Contact not found.\n";
        }
    }

    // Function to search for contacts by street
    void searchByStreet(string ulica)
    {
        auto& street_index = contacts.get<by_street>();
        auto range = street_index.equal_range(ulica);
        cout << "Contacts on street " << ulica << ":\n";
        for (auto it = range.first; it != range.second; ++it)
        {
            cout << it->imie << " " << it->nazwisko << "\n";
        }
    }

    // Function to search for contacts within an age range
    void searchByAge(int min, int max)
    {
        auto& age_index = contacts.get<by_age>();
        // lower_bound returns an iterator to the first element not less than the key,
        // upper_bound returns an iterator to the first element greater than the key
        for (auto it = age_index.lower_bound(min); it != age_index.upper_bound(max); ++it) 
        {
            cout << it->imie << " " << it->nazwisko << " (Age: " << it->wiek << ")\n";
        }
    }

    // Function to find a contact by number
    void searchByNumber(string numer)
    {
        auto& number_index = contacts.get<by_number>();
        auto it = number_index.find(numer);
        if (it != number_index.end())
        {
            cout << it->imie << " " << it->nazwisko << " (Phone: " << it->numer << ")\n";
        }
        else
        {
            cout << "Contact not found.\n";
        }
    }

    // Function to change the street name for all contacts on a given street
    void changeStreet(string ulica, string newUlica)
    {
        auto& street_index = contacts.get<by_street>();
        auto range = street_index.equal_range(ulica);
        // range.first - iterator to the first element in the range, 
        // range.second - iterator to the element following the last element in the range
        // for example: 
        // container: 1 2 3 4 5 6 7 8 9
        // range: 4 5 6
        // range.first points to 4, range.second points to 7
        for (auto it = range.first; it != range.second; ++it)         {
            // const_cast - removes the constness of the object pointed to by it->ulica
            // <string&> - reference to string
            // (it->ulica) - the object pointed to by it->ulica
            // = newUlica - assign newUlica to the object pointed to by it->ulica
            const_cast<string&>(it->ulica) = newUlica;
        }
    }

    // Count adults in the address book
    void countAdults()
    {
        int count = 0;
        for (const auto& contact : contacts)
        {
            if (contact.isAdult())
                ++count;
        }
        cout << "Number of adults: " << count << "\n";
    }

    // Count unique surnames
    void countUniqueSurnames()
    {
        set<string> unique_surnames;
        for (const auto& contact : contacts)
        {
            unique_surnames.insert(contact.nazwisko);
        }
        cout << "Unique surnames: " << unique_surnames.size() << "\n";
    }

    // Show all contacts
    void showContacts()
    {
        cout << "All contacts:\n";
        for (const auto& contact : contacts)
        {
            cout << contact.imie << " " << contact.nazwisko << ", Age: " << contact.wiek
                 << ", Phone: " << contact.numer << ", Street: " << contact.ulica << "\n";
        }
    }
};

#endif // CONTACTS_H_INCLUDED
