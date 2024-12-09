// Zdefiniuj wyrażenia regularne pozwalające na sprawdzenie:
//  ulicy (nazwa może składać się tylko z liter alfabetu łacińskiego i pierwsza litera jest
// dużą literą, a pozostałe liter są małe);
//  kodu pocztowego (w formacie XX-XXX, gdzie X to cyfra);
//  numeru domu (liczba lub liczba i litera, np. 28, 28B);
//  numer mieszkania
// W funkcji main należy przetestować stworzone wyrażenia regularne.

#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main() {
    string line;
    cout << "Podaj łańcuch znaków: ";
    getline(cin, line);

    vector<tuple<string, string, regex>> patterns = {
        {"nazwa ulicy", "nazwy ulicy", regex("\\b[AaUu]l\\. ([A-Z]|[0-9]+)([0-9a-zA-Z]+)*\\b")},
            // \b - granica słowa
            // [AaUu]l\\. - ul. albo al.
            // [A-Z] - duża litera alfabetu łacińskiego
            // [a-z] - mała litera alfabetu łacińskiego
            // + - jedna lub więcej wystąpień
            // (?: ) - grupa niezapamiętująca - nie jest zapisywana w wyniku
            // * - zero lub więcej wystąpień
            // \b - granica słowa

        {"kod pocztowy", "kodu pocztowego", regex("\\b[0-9]{2}-[0-9]{3}\\b")},
            // [0-9] - cyfra od 0 do 9
            // {2} - dokładnie 2 wystąpienia
            // - - myślnik
            // {3} - dokładnie 3 wystąpienia

        {"numer domu", "numeru domu", regex("\\b[0-9]+[A-Z]?")},
            // [0-9] - cyfra od 0 do 9
            // + - jedna lub więcej wystąpień
            // [A-Z]? - opcjonalna duża litera alfabetu łacińskiego

        {"numer mieszkania", "numeru mieszkania", regex("/[0-9]+\\b")}
            // / - /
            // [0-9]+ - cyfry od 0 do 9

    };

    for (const auto& element : patterns) {
        string descTrue = get<0>(element);
        string descFalse = get<1>(element);
        regex pattern = get<2>(element);
        if (regex_search(line, pattern)) {
            cout << "Znaleziono " << descTrue << ".\n";
        } else {
            cout << "Nie znaleziono " << descFalse << ".\n";
        }
    }

    return 0;
}
