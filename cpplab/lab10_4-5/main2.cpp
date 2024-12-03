// Wykorzystaj plik stworzony w zadaniu 10.4. i na jego podstawie wyświetl następujące
// informacje:
//  nazwy unikatowych domen;
//  numery telefonów, które kończą się liczbą parzystą;
//  nazwiska łączone.

#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main() {
    ifstream file("dane.txt"); 
    if (!file) {
        cerr << "Nie udało się otworzyć pliku!" << endl;
        return 1;
    }

    set<string> unique_domains; 
    set<string> surnames_connected;  
    vector<string> phone_numbers_even;  

    string line;
    while (getline(file, line)) {
        string name, surname, phone_number, email;
        stringstream ss(line);

        getline(ss, name, ';');
        getline(ss, surname, ';');
        getline(ss, phone_number, ';');
        getline(ss, phone_number, ';'); // Pominięcie wieku
        getline(ss, email, ';');

        size_t at_pos = email.find('@');
        if (at_pos != string::npos) {
            string domain = email.substr(at_pos + 1);
            unique_domains.insert(domain);
        }

        if (!phone_number.empty()) {
            int last_digit = phone_number.back() - '0'; 
            if (last_digit % 2 == 0) {
                phone_numbers_even.push_back(phone_number);
            }
        }

        if (surname.find('-') != string::npos) {
            surnames_connected.insert(surname);
        }
    }

    cout << "Unikatowe domeny:" << endl;
    for (const string &domain : unique_domains) {
        cout << domain << endl;
    }

    cout << "Numery telefonów kończące się liczbą parzystą:" << endl;
    for (const string &phone : phone_numbers_even) {
        cout << phone << endl;
    }

    cout << "Nazwiska łączone:" << endl;
    for (const string &surname : surnames_connected) {
        cout << surname << endl;
    }

    file.close(); 
    return 0;
}

