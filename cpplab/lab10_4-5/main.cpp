// Zdefiniuj wyrażenia regularne pozwalające na sprawdzenie:
//  imienia (imię może składać się tylko z liter alfabetu łacińskiego);
//  nazwisko (nazwisko może składać się z liter alfabetu łacińskiego oraz myślnika przy
// nazwiskach łączonych, na przykład: Nowak-Kowalska);
//  wieku (liczba od 0 do 99);
//  numeru telefonu komórkowego (numer telefonu składa się z 9 cyfr, przy czym
// pierwsza cyfra nie może być 0);
//  emaila (email postaci u@x.y, gdzie u to nazwa użytkownika, która może składać się
// z liter alfabetu łacińskiego, cyfr oraz znaków: podkreślenie, minus, plus, wykrzyknik,
// kropka oraz nie może zaczynać się od cyfry, znaku podkreślenia, kropki oraz
// myślnika, x.y to nazwa domeny, która może składać się z liter alfabetu łacińskiego
// oraz cyfr);
// Napisz program, który będzie wczytywał od użytkownika: imię, nazwisko, wiek, numer
// telefonu komórkowego oraz email i sprawdzał za pomocą zdefiniowanych wyrażeń
// regularnych czy podane dane są prawidłowe. Jeśli użytkownik podał prawidłowe dane to
// należy zapisać te dane do pliku w jednej linijce, w której zostaną one rozdzielone średnikiem.

#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string imie, nazwisko, wiek, telefon, email;
    cout << "Podaj imię: ";
    getline(cin, imie);
    cout << "Podaj nazwisko: ";
    getline(cin, nazwisko);
    cout << "Podaj wiek: ";
    getline(cin, wiek);
    cout << "Podaj numer telefonu komórkowego: ";
    getline(cin, telefon);
    cout << "Podaj email: ";
    getline(cin, email);

    vector<tuple<string, string, regex, string>> patterns = {
        {"imię", "imienia", regex("\\b[A-Za-z]+\\b"), imie},
        {"nazwisko", "nazwiska", regex("\\b[A-Za-z]+(?:-[A-Za-z]+)?\\b"), nazwisko},
        {"wiek", "wieku", regex("\\b[0-9]{1,2}\\b"), wiek},
        {"numer telefonu komórkowego", "numeru telefonu komórkowego", regex("\\b[1-9][0-9]{8}\\b"), telefon},
        {"email", "emaila", regex("\\b[A-Za-z][A-Za-z0-9_.+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b"), email}
    };

    bool czyPoprawne = true;

    for (const auto& element : patterns) {
        string descTrue = get<0>(element);
        string descFalse = get<1>(element);
        regex pattern = get<2>(element);
        string inputValue = get<3>(element);
        
        if (regex_search(inputValue, pattern)) {
            cout << "Znaleziono " << descTrue << ".\n";
        } else {
            cout << "Nie znaleziono " << descFalse << ".\n";
            czyPoprawne = false;
        }
    }
    if (czyPoprawne) {
        cout << "Dane są poprawne.\n";
        ofstream file("dane.txt", ios::app); 
        if (file.is_open()) {
            file << imie << ";" << nazwisko << ";" << wiek << ";" << telefon << ";" << email << endl;
            file.close();  
        } else {
            cerr << "Nie udało się otworzyć pliku!" << endl;
        }
    }
    else {
        cout << "Dane są niepoprawne.\n";
        return 1;
    }


    return 0;
}