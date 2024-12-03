// Zdefiniuj wyrażenie regularne, które pozwoli na sprawdzenie czy w danym łańcuchu znaków
// znajduje się liczba zmiennoprzecinkowa ze znakiem (liczba całkowita od części ułamkowej
// oddzielona jest kropką, np. +6.789, -7.234). W funkcji main należy przetestować stworzone
// wyrażenia regularne.

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string line;
    cout << "Podaj łańcuch znaków: ";
    getline(cin, line);
    regex wzor("[-+]?[0-9]+\\.[0-9]+");
    if(regex_search(line, wzor)) {
        cout << "Znaleziono liczbę zmiennoprzecinkową ze znakiem.\n";
    }
    else {
        cout << "Nie znaleziono liczby zmiennoprzecinkowej ze znakiem.\n";
    }
    return 0;
}