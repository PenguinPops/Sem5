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

    // Wyrażenie bez użycia lookbehind/lookahead
    regex wzor("(?:^|[^\\d+\\-=])\\s*[+-]\\d+\\.\\d+\\s*(?:$|[^\\d+\\-=])");
        // (?:^|[^\\d+\\-=]) - początek linii lub znak, który nie jest cyfrą, +, -, =
        // \\s* - zero lub więcej białych znaków
        // [+-] - + lub -
        // \\d+ - jedna lub więcej cyfr
        // \\. - kropka
        // \\d+ - jedna lub więcej cyfr
        // \\s* - zero lub więcej białych znaków
        // (?:$|[^\\d+\\-=]) - koniec linii lub znak, który nie jest cyfrą, +, -, =

    if (regex_search(line, wzor)) {
        cout << "Znaleziono liczbę zmiennoprzecinkową ze znakiem " << endl;
    }
    else {
        cout << "Nie znaleziono liczby zmiennoprzecinkowej ze znakiem "<< endl;
    }
    return 0;
}