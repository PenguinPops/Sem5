// Zdefiniuj wyrażenie regularne do rozpoznawania godziny. Zakładamy, że zapis godziny jest
// następujący: hh:mm:ss lub hh:mm, gdzie hh to godziny (0-23), mm - liczba minut (0-59),
// ss – to liczba sekund (0-59). Podawanie sekund jest opcjonalne. Liczby (hh,mm,ss) zawsze
// zapisane są za pomocą dwóch cyfr. W funkcji main należy przetestować stworzone wyrażenia
// regularne.

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string line;
    cout << "Podaj łańcuch znaków: ";
    getline(cin, line);
    regex wzor("([01]?[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]");
    if(regex_search(line, wzor)) {
        cout << "Znaleziono godzinę w formacie hh:mm:ss.\n";
    }
    else {
        cout << "Nie znaleziono godziny w formacie hh:mm:ss.\n";
    }
    regex wzor2("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    if(regex_search(line, wzor2)) {
        cout << "Znaleziono godzinę w formacie hh:mm.\n";
    }
    else {
        cout << "Nie znaleziono godziny w formacie hh:mm.\n";
    }
    return 0;
}